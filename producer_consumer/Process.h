/*
 * Process.h
 *
 *  Created on: 14-Oct-2020
 *      Author: johna
 */

#include <pthread.h>

#ifndef PROCESS_H_
#define PROCESS_H_

class Process {
private:
	int count;
	const static int LIMIT = 10;
public:
	Process();

	void *consumer(void *nonused);
	void *producer(void *nonused);
	static void *startPro(void *context);
	static void *startCon(void *context);
};

#endif /* PROCESS_H_ */
