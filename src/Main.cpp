#include <iostream>
using namespace std;

#include <unistd.h>
#include "MyWorker.h"


int main() {
	cout << "cpp worker running" << endl;

	MyWorker w;

	if (w.start() == 0) {
		usleep(10000000); // Let thread run 10 seconds
		w.stop();
	}
	else {
		cout << "Error!" << endl;
	}

	return 0;
}
