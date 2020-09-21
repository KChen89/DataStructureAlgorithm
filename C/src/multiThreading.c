#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>
#include<unistd.h>
#include "headers.h"

#define MAX_THREADS 5

void* performWork(void* args){
    unsigned int index = *((int*) args);
    unsigned int sleepTime = 1 + rand() % MAX_THREADS;
    printf("Thread started ID: %d sleep time: %d\n", index, sleepTime);
    sleep(sleepTime);
    printf("Thread ended ID: %d\n", index);
    return NULL;
}

void testThread(void){
    pthread_t threadArray[MAX_THREADS];
    int threadArgs[MAX_THREADS];
    int i;
    int resultCode;

    for(i=0; i<MAX_THREADS; i++){
        printf("IN TEST: create thread %d\n", i);
        threadArgs[i] = i;
        resultCode = pthread_create(&threadArray[i], NULL, performWork, &threadArgs[i]);
        assert(!resultCode);
    }

    printf("IN TEST: all threads are created\n");
    for(i=0;i<MAX_THREADS;i++){
        resultCode = pthread_join(threadArray[i], NULL);
        assert(!resultCode);
        printf("IN TEST: Thread %d was ended\n", i);
    }
    printf("TEST ended\n");
}

