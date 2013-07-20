/*
 * ThreadPoolBase.hpp
 *
 *  Created on: 30.06.2013
 *      Author: Admin
 */

#ifndef THREADPOOLBASE_HPP_
#define THREADPOOLBASE_HPP_

#include "WorkerThread.hpp"
#include <vector>

enum ExecutionType{
	Async, Sync
};

class ThreadPoolBase {
public:
	ThreadPoolBase() {

	}
	virtual ~ThreadPoolBase() {
		for (std::vector<WorkerThread*>::iterator it = threads.begin();
				it != threads.end(); it++) {
			delete *it;
		}
	}
	void addTask(funcObject* func) {
		tasks.push_back(func);
	}
	virtual void startExecution(ExecutionType type) = 0;
protected:
	void addThread() {
		threads.push_back(new WorkerThread(nullptr, threads.size()));
	}
	//thread container
	std::vector<WorkerThread*> threads;
	//task container
	std::vector<funcObject*> tasks;
};

#endif /* THREADPOOLBASE_HPP_ */
