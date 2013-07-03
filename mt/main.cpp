/*
 * main.cpp
 *
 *  Created on: 30.06.2013
 *      Author: Admin
 */
#define BOOST_THREAD_USE_LIB

#include "Pool/WorkerThread.hpp"
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Tests/WorkerThreadTest.hpp"
void foo1() {
	for (int i = 0; i < 100; i++) {
		std::cout << "foo1" << std::endl;
	}
}

void foo2() {
	for (int i = 0; i < 100; i++) {
		std::cout << "foo2" << std::endl;
	}
}

//int main() {
//	boost::thread t1(foo1);
//	t1.detach();
//	boost::thread t2(foo2);
//	t2.detach();
//	while(1){}
//	return 0;
//}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
