/*
 * FixedThreadPool.hpp
 *
 *  Created on: 30.06.2013
 *      Author: Admin
 */

#ifndef FIXEDTHREADPOOL_HPP_
#define FIXEDTHREADPOOL_HPP_

#include <stdint.h>
#include "ThreadPoolBase.hpp"
#include "../Log.hpp"

class FixedThreadPool: public ThreadPoolBase {
public:
	FixedThreadPool(uint32_t threadsCount) {
		for (uint32_t i = 0; i < threadsCount; i++) {
			addThread();
		}
	}
	virtual ~FixedThreadPool() {

	}
	virtual void startExecution(ExecutionType type) {
		switch (type) {
		case Sync:
			while (!tasks.empty()) {
				for (std::vector<WorkerThread*>::iterator it = threads.begin();
						it != threads.end(); it++) {
					if ((*it)->isFinished()) {
						(*it)->setFunction(*tasks.begin());
						(*it)->startExecution();
						tasks.erase(tasks.begin());

					}
					if (tasks.empty()) {
						break;
					}
				}
			}
			Log::err("joining\n");
			for (std::vector<WorkerThread*>::iterator it = threads.begin();
					it != threads.end(); it++) {
				(*it)->join();
			}
			break;
		}
	}
};

#endif /* FIXEDTHREADPOOL_HPP_ */
