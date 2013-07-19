/*
 * WorketThreadTest.hpp
 *
 *  Created on: 02.07.2013
 *      Author: Admin
 */

#ifndef WORKETTHREADTEST_HPP_
#define WORKETTHREADTEST_HPP_

#include <unistd.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Pool/WorkerThread.hpp"
#include <iostream>
#include "boost/chrono.hpp"

class WorkerThreadTest: public ::testing::Test {
protected:
	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};

TEST_F (WorkerThreadTest, simpleRun) {
	int complete1 = 0;
	int complete2 = 0;
	boost::chrono::milliseconds dura(50);

	funcObject thread1 = [&]() {
		for(int i=0;i<30;i++) {
			std::cout<<"a\n";
			usleep(5000);
		}
		complete1=1;
	};
	funcObject thread2 = [&]() {
		for(int i=0;i<30;i++) {
			std::cout<<"b\n";
			usleep(1000);
//			boost::this_thread::sleep_for( dura );
		}
		complete2=1;
	};
	WorkerThread worker1(&thread1);
	WorkerThread worker2(&thread2);
	worker1.startExecution();
	worker2.startExecution();
	while (!(complete1 && complete2)) {
	}
	worker1.join();
	worker2.join();
}

#endif /* WORKETTHREADTEST_HPP_ */
