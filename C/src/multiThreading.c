#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>
#include<unistd.h>
#include "headers.h"

#define MAX_THREADS 5

void* performWork(void* args){
    int index = *((int*) args);
    
    unsigned int* sleepTime;
    sleepTime = malloc(sizeof(sleepTime));
    *sleepTime = 1+ rand() % MAX_THREADS;
    printf("Thread started ID: %d sleep time: %u\n", index, *sleepTime);
    sleep(*sleepTime);
    printf("Thread ended ID: %d\n", index);
    pthread_exit((void*) sleepTime);
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
    unsigned int* sTime;
    for(i=0;i<MAX_THREADS;i++){
        resultCode = pthread_join(threadArray[i], (void**) &sTime);
        assert(!resultCode);
        printf("IN TEST: Thread %d was ended after sleep %u\n", i, *sTime);
    }
    free(sTime);
    printf("TEST ended\n");
}

