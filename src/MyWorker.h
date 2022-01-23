#ifndef MYWORKER_H_
#define MYWORKER_H_

#include <iostream>
#include "IWorker.h"


class MyWorker : public IWorker {
public:
	MyWorker() {};
	virtual ~MyWorker() { std::cout << "~MyWorker" << std::endl; };


	void work() override {

		while (!mStop) {
			std::cout << "Running ..." << std::endl;
			usleep(1000000); // 1 second
		}
		std::cout << "Stopped" << std::endl;
	}

};

#endif
