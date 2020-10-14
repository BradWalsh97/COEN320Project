#include <stdio.h>
#include <pthread.h>
#include "process.h"

int main (int argc, char *argv[]) {
	pthread_t pid;
	pthread_t cid;
	printf ("Starting consumer/producer example...\n");
	while(1){
	    // create the producer and consumer threads
	    pthread_create (&pid, NULL, producer, NULL);
	    pthread_create (&cid, NULL, consumer, NULL);
	    //pthread_join(pid, NULL);
	    //pthread_join(cid, NULL);
	}
}
