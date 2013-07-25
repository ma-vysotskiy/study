/*
 * ThreadPoolBaseTest.hpp
 *
 *  Created on: 04.07.2013
 *      Author: Admin
 */

#ifndef THREADPOOLBASETEST_HPP_
#define THREADPOOLBASETEST_HPP_

#include <unistd.h>
#include <boost/thread.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Pool/FixedThreadPool.hpp"

class FixedThreadPoolTest: public ::testing::Test {
protected:
	virtual void SetUp() {
		thread1 = [&]() {
			for(int i=0;i<1;i++) {
				controlMutex.lock();
				controlVariable++;
				controlMutex.unlock();
			}
		};
	}
	virtual void TearDown() {

	}
	uint32_t controlVariable;
	boost::mutex controlMutex;
	funcObject thread1;
};

TEST_F(FixedThreadPoolTest, oneSyncThreadTest) {
	FixedThreadPool pool(1);
	controlVariable = 0;
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);
	EXPECT_EQ(controlVariable, 4);
}

TEST_F(FixedThreadPoolTest, twoSyncThreadTest) {
	FixedThreadPool pool(2);
	controlVariable = 0;
	//TODO: fix fails sometimes. result 3 when waiting 4.
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);
	EXPECT_EQ(controlVariable, 4);
}

TEST_F(FixedThreadPoolTest, threeSyncThreadTest) {
	FixedThreadPool pool(3);
	controlVariable = 0;
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);
	EXPECT_EQ(controlVariable, 4);
}

TEST_F(FixedThreadPoolTest, fiveSyncThreadTest) {
	FixedThreadPool pool(5);
	controlVariable = 0;
	pool.addTask(&thread1);
	pool.addTask(&thread1);

	pool.startExecution(Sync);
	EXPECT_EQ(controlVariable, 2);
}

#endif /* THREADPOOLBASETEST_HPP_ */
