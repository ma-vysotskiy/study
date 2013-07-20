/*
 * WorkerThread.hpp
 *
 *  Created on: 01.07.2013
 *      Author: Admin
 */

#ifndef WORKERTHREAD_HPP_
#define WORKERTHREAD_HPP_

#include <functional>
#include <list>
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>
#include "../Log.hpp"
class worker_joined: public std::exception {

};
typedef std::function<void()> funcObject;
class WorkerThread {
public:
	WorkerThread(funcObject* func, int i) :
			i(i), currentState(WAITING), totalTasksExecuted(0), totalTasksAccepted(
					0), thr(worker, this), lock(waitMutex) {
		setFunction(func);
	}
	void startExecution() throw (worker_joined) {
		if (currentState == JOINED) {
			throw worker_joined();
		}
		std::stringstream out;
		out << i;
		Log::err("startExecution " + out.str() + "\n");
		waitMutex.unlock();

	}

	void setFunction(funcObject* func) throw (worker_joined) {
		if (currentState == JOINED) {
			throw worker_joined();
		}
		tasksMutex.lock();
		if (func != nullptr) {
			tasks.push_back(func);
			totalTasksAccepted++;
		}
		tasksMutex.unlock();
	}
	void join() {
		if (currentState != JOINED) {
			setState(JOINING);
			thr.join();
			setState(JOINED);
		}
	}
	bool isFinished() {
		return totalTasksAccepted == totalTasksExecuted;
	}
private:
	enum STATE {
		WAITING, EXECUTING, JOINING, JOINED
	};
	void setState(STATE st) {
		stateMutex.lock();
		if ((currentState != JOINING) && (currentState != JOINED)) {
			std::stringstream out;
			currentState = st;
			out << currentState;
			Log::err("Currstate " + out.str() + "\n");
		}
		stateMutex.unlock();
	}
	static void worker(WorkerThread* obj) {
		std::stringstream out;
		out << obj->i;
		std::stringstream out2;
				out2 << obj->i;
		Log::err("\tworker started" + out.str() + "\n");
		do {
			obj->setState(WAITING);
			while (obj->tasks.empty()) {
//				Log::err("\tworker waiting " + out.str() + "\n");
//				obj->waitMutex.lock();
				if (obj->currentState == JOINING) {
					goto exit;
				}
			}
			Log::err("\tworker executing " + out.str() + "\n");
			obj->setState(EXECUTING);
			funcObject* currentTask = *obj->tasks.begin();
			(*currentTask)();
			std::stringstream info;
			out << obj->tasks.size() << ' ' << obj->currentState;
			Log::err(
					"\tworker executed " + out.str() + " " + info.str()
							+ " \n");
			obj->totalTasksExecuted++;
			obj->tasks.pop_front();
		} while (!(obj->tasks.empty() && (obj->currentState == JOINING)));
		exit: Log::err("\tworker " + out2.str() + " exited");
	}

	int i;
	STATE currentState;
	uint32_t totalTasksExecuted;
	uint32_t totalTasksAccepted;
	std::list<funcObject*> tasks;
	boost::mutex tasksMutex;
	boost::mutex stateMutex;
	boost::mutex waitMutex;
	boost::lock_guard<boost::mutex> lock;
	boost::thread thr;
};
/*
 class WorkerThread {
 public:
 WorkerThread(funcObject* func, int i) :
 workerStopped(true), dataReadyMutex(), lock(dataReadyMutex), thr(
 worker, this), threadFunction(func), i(i) {
 }
 void setFunction(funcObject* func) {
 threadFunctionMutex.lock();
 threadFunction = func;
 threadFunctionMutex.unlock();
 }

 void startExecution() {
 dataReadyMutex.unlock();
 std::stringstream out;
 out << i;
 Log::err("startExecution " + out.str() + "\n");

 }
 bool isFinished() {
 bool res = dataReadyMutex.try_lock();
 if (res) {
 dataReadyMutex.unlock();
 }
 return !res;
 }
 void join() {
 Log::err("join");

 std::stringstream out;
 out << i;

 threadFunctionMutex.lock();
 Log::err("\tjoin func locked " + out.str() + "\n");
 threadFunction = nullptr;
 Log::err("\tjoin func nulled " + out.str() + "\n");
 threadFunctionMutex.unlock();
 Log::err("\tjoin func unlocked " + out.str() + "\n");
 dataReadyMutex.unlock();
 Log::err("\tjoin cont unlocked " + out.str() + "\n");
 //		thr.join();
 Log::err("\tjoined " + out.str() + "\n");
 }
 private:
 static void worker(WorkerThread* obj) {


 std::stringstream out;
 out << obj->i;

 obj->dataReadyMutex.lock();
 Log::err("\t\tworker started " + out.str() + "\n");
 while (obj->threadFunction != nullptr) {
 obj->threadFunctionMutex.lock();
 Log::err("\t\tfunc locked " + out.str() + "\n");
 (*obj->threadFunction)();
 Log::err("\t\tfunc executed " + out.str() + "\n");
 obj->threadFunctionMutex.unlock();
 Log::err("\t\tfunc unlocked " + out.str() + "\n");
 obj->dataReadyMutex.lock();
 Log::err("\t\tworker unlocked " + out.str() + "\n");
 }
 Log::err("\tworker exit " + out.str() + "\n");
 }
 int i;
 bool workerStopped;
 boost::mutex dataReadyMutex;
 boost::mutex threadFunctionMutex;
 boost::lock_guard<boost::mutex> lock;
 boost::thread thr;
 funcObject* threadFunction;
 };
 */
#endif /* WORKERTHREAD_HPP_ */
