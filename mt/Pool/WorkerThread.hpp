/*
 * WorkerThread.hpp
 *
 *  Created on: 01.07.2013
 *      Author: Admin
 */

#ifndef WORKERTHREAD_HPP_
#define WORKERTHREAD_HPP_

#include <functional>
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>

typedef std::function<void()> funcObject;

class WorkerThread {
public:
	WorkerThread(funcObject* func) :
			dataReadyMutex(), lock(dataReadyMutex), thr(worker, this), threadFunction(
					func) {
	}
	void setFunction(funcObject* func) {
		threadFunction = func;
	}

	void startExecution(){
		dataReadyMutex.unlock();
	}
private:
	static void worker(WorkerThread* obj) {
		obj->dataReadyMutex.lock();
		// do job
		(*obj->threadFunction)();
		obj->dataReadyMutex.unlock();
	}
	boost::mutex dataReadyMutex;
	boost::lock_guard<boost::mutex> lock;
	boost::thread thr;
	funcObject* threadFunction;
};

#endif /* WORKERTHREAD_HPP_ */
