#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include "Process.h"

int main(int argc, char *argv[]) {
		Process process;
		std::cout<<"Starting consumer/producer example..."<<std::endl;
		for(;;){
		    // create the producer and consumer threads
		    pthread_create(NULL, NULL, &Process::startPro, &process);
		    pthread_create(NULL, NULL, &Process::startCon, &process);
		    //pthread_join(pid, NULL);
		    //pthread_join(cid, NULL);
		}
	return EXIT_SUCCESS;
}
