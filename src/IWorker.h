#ifndef IWORKER_H_
#define IWORKER_H_

#include <atomic>
#include <thread>


class IWorker {
public:
	IWorker() {}
	virtual ~IWorker() {}

	virtual void work() = 0; // implementation


	void start() {
		std::thread thrd(
				[](void* self) {
					static_cast<IWorker*>(self)->work();
					return nullptr;
				},
				this); // 'this' as argument to lambda

		mThd = std::move(thrd);
	}

	void stop() {
		mStop = true;
		// wait for the thread to exit by joining
		mThd.join();
	}


protected:
	std::thread mThd{};
	std::atomic<bool> mStop{};
};

#endif
