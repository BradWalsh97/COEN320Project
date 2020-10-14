/*
 * Process.cpp
 *
 *  Created on: 14-Oct-2020
 *      Author: johna
 */

#include <iostream>
#include <unistd.h>
#include "Process.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

Process::Process() {
	this->count = 0;
}

void *Process::consumer(void *nonused){
	for(;;){
			pthread_mutex_lock(&mutex);
			std::cout<<"In consumer thread..."<<std::endl;;
			while(this->count == 0){
				pthread_cond_wait(&condvar, &mutex);
			}
			//process data
			this->count--;
			std::cout<<"consumed consumed data, count is "<<this->count<<std::endl;
			sleep(1);
			pthread_cond_signal(&condvar);
			pthread_mutex_unlock(&mutex);
		}
}

void *Process::producer(void *nonused){
	for(;;){
			pthread_mutex_lock(&mutex);
			std::cout<<"In producer thread..."<<std::endl;
			while(this->count == LIMIT){
				pthread_cond_wait(&condvar, &mutex);
			}
			this->count++;
			std::cout<<"producer produced data, count is "<<this->count<<std::endl;
			sleep(1);
			pthread_cond_signal(&condvar);
			pthread_mutex_unlock(&mutex);
		}
}

void *Process::startPro(void *context){
	return ((Process *)context)->producer(NULL);
}

void *Process::startCon(void *context){
	return ((Process *)context)->consumer(NULL);
}
