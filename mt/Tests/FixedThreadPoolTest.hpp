/*
 * ThreadPoolBaseTest.hpp
 *
 *  Created on: 04.07.2013
 *      Author: Admin
 */

#ifndef THREADPOOLBASETEST_HPP_
#define THREADPOOLBASETEST_HPP_

#include <unistd.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Pool/FixedThreadPool.hpp"

class FixedThreadPoolTest: public ::testing::Test {
protected:
	virtual void SetUp() {
	 thread1 = [&]() {
			for(int i=0;i<2;i++) {
				std::cout<<"\tthreadbody\n";
				usleep(50);
			}
		};
	}
	virtual void TearDown() {

	}

	funcObject thread1;
};

TEST_F(FixedThreadPoolTest, oneSyncThreadTest) {
	FixedThreadPool pool(1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);

}

TEST_F(FixedThreadPoolTest, twoSyncThreadTest) {
	FixedThreadPool pool(2);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);

}

TEST_F(FixedThreadPoolTest, threeSyncThreadTest) {
	FixedThreadPool pool(3);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);

}

TEST_F(FixedThreadPoolTest, fiveSyncThreadTest) {
	FixedThreadPool pool(3);
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);

}

#endif /* THREADPOOLBASETEST_HPP_ */
