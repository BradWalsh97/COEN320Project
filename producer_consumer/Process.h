#include <pthread.h>
#include <stdio.h>

#ifndef PROCESS_H_
#define PROCESS_H_

int count = 0;
const int LIMIT = 10;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

void *consumer(void *nonused){
	while(1){
		pthread_mutex_lock(&mutex);
		printf("In consumer thread...\n");
		while(count == 0){
			pthread_cond_wait(&condvar, &mutex);
		}
		//process data
		count--;
		printf("consumed consumed data, count is %d\n", count);
		sleep(1);
		pthread_cond_signal(&condvar);
		pthread_mutex_unlock(&mutex);
	}
}

void *producer(void *nonused){
	while(1){
		pthread_mutex_lock(&mutex);
		printf("In producer thread...\n");
		while(count == LIMIT){
			pthread_cond_wait(&condvar, &mutex);
		}
		count++;
		printf("producer produced data, count is %d\n", count);
		sleep(1);
		pthread_cond_signal(&condvar);
		pthread_mutex_unlock(&mutex);
	}
}


#endif
