/*
 * ThreadPoolBase.hpp
 *
 *  Created on: 30.06.2013
 *      Author: Admin
 */

#ifndef THREADPOOLBASE_HPP_
#define THREADPOOLBASE_HPP_

class ThreadPoolBase {
public:
	ThreadPoolBase() {

	}
	virtual ~ThreadPoolBase() {

	}

protected:
	void addThread();
	void addTask();
private:
	//thread container
	//task container
};

#endif /* THREADPOOLBASE_HPP_ */
