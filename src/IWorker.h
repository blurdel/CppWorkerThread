#ifndef IWORKER_H_
#define IWORKER_H_

#include <atomic>
#include <thread>


class IWorker {
public:
	IWorker() {};
	virtual ~IWorker() {};

	virtual void run() = 0; // implementation


	int start() {
		return pthread_create(
				&mThreadId,
				nullptr,
				[](void* self) -> void* { // captureless lambda
					static_cast<IWorker*>(self)->run();
					return nullptr;
				},
				this); // 'this' as argument to lambda
	}

	void stop() {
		mStop = true;
		// wait for the thread to exit by joining
		pthread_join(mThreadId, nullptr);
	}


protected:
	pthread_t mThreadId { 0 };
	std::atomic<bool> mStop { false };
};

#endif
