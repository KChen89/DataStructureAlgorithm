#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include "headers.h"

#define MAX_THREADS 5
unsigned int counter;
// pthread_mutex_t lock;

void* performWork(void* args){
    int index = *((int*) args);
    
    unsigned int* sleepTime;
    sleepTime = malloc(sizeof(sleepTime));
    *sleepTime = 1+ rand() % MAX_THREADS;
    printf("Thread started ID: %d sleep time: %u\n", index, *sleepTime);
    sleep(*sleepTime);
    printf("Thread ended ID: %d\n", index);
    pthread_exit((void*) sleepTime);
    free(sleepTime);
}

void testThread(void){
    pthread_t threadArray[MAX_THREADS];
    int i;
    int resultCode;

    for(i=0; i<MAX_THREADS; i++){
        printf("IN TEST: create thread %d\n", i);
        // threadArgs[i] = i;
        int arg = i;
        resultCode = pthread_create(&threadArray[i], NULL, performWork, &arg);
        assert(!resultCode);
    }

    printf("IN TEST: all threads are created\n");
    unsigned int* sTime;
    for(i=0;i<MAX_THREADS;i++){
        resultCode = pthread_join(threadArray[i], (void**) &sTime);
        assert(!resultCode);
        printf("IN TEST: Thread %d was ended after sleep %u\n", i, *sTime);
    }
    // free(sTime);
    printf("TEST ended\n");
}

void* pTask(void* lockP){
    // int index = *((int*) args);
    // pthread_mutex_t lock = *((pthread_mutex_t*) args);
    pthread_mutex_lock((pthread_mutex_t*) lockP);
    // pthread_mutex_lock(&lock);
    unsigned int* sleepTime;
    sleepTime = malloc(sizeof(sleepTime));
    *sleepTime = 1 + rand() % MAX_THREADS;
    counter++;
    printf("Thread %d starts. Time cost: %d \n", counter, *sleepTime);
    sleep(*sleepTime);
    printf("Thread %d ends\n", counter);
    pthread_mutex_unlock((pthread_mutex_t*) lockP);
    // pthread_mutex_unlock(&lock);
    pthread_exit((void*) sleepTime);
    free(sleepTime);
}

void testMutex(void){
    pthread_t taskList[2];
    int ret;
    int i;
    pthread_mutex_t lock;
    ret = pthread_mutex_init(&lock, NULL);
    assert(!ret);

    for(i=0; i<2; i++){
        ret = pthread_create(&taskList[i], NULL, pTask, &lock);
        assert(!ret);
    }
    unsigned int* sTime;
    for(i=0;i<2;i++){
        ret = pthread_join(taskList[i], (void**) &sTime);
        assert(!ret);
        printf("Thread %d returned %d \n", i+1, *sTime);
    }
    pthread_mutex_destroy(&lock);
}


void* sTask(void* semaphore){
    int ret;
    ret = sem_wait(semaphore);
    assert(!ret);
    unsigned int* sleepTime;
    sleepTime = malloc(sizeof(sleepTime));
    *sleepTime = 1 + rand() % MAX_THREADS;
    counter++;
    printf("Thread %d starts. Time cost %d \n", counter, *sleepTime);
    sleep(*sleepTime);
    printf("Thread %d ends \n", counter);
    ret = sem_post(semaphore);
    assert(!ret);
    pthread_exit((void*) sleepTime);
    free(sleepTime);
}

void testSemaphore(void){
    pthread_t taskList[2];
    int ret;
    int i;
    sem_t semaphore;
    ret = sem_init(&semaphore, 0, 1);
    assert(!ret);
    for(i=0;i<2;i++){
        ret = pthread_create(&taskList[i], NULL, sTask, &semaphore);
        assert(!ret);
    }
    unsigned int* sTime;
    for(i=0;i<2;i++){
        ret = pthread_join(taskList[i], (void**) &sTime);
        assert(!ret);
        printf("Thread %d returned %d\n", i+1, *sTime);
    }
    sem_destroy(&semaphore);
}