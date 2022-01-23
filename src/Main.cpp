#include <iostream>
using namespace std;

#include <unistd.h>
#include "MyWorker.h"


int main() {
	cout << "cpp worker running" << endl;

	MyWorker w;

	w.start();
	usleep(5000000); // Let thread run 5 seconds
	w.stop();

	return 0;
}
