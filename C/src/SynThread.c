#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include "headers.h"

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

int count = 0;

void testSynThread(void){
    pthread_t taskList[2];
    int ret;
    pthread_mutex_t lock;
    ret = pthread_mutex_init(&lock, NULL);
    assert(!ret);
    printf("Start creating threads\n");

    ret = pthread_create(&taskList[0], NULL, counter0, &lock);
    assert(!ret);
    printf("Thread 0 created\n");
    ret = pthread_create(&taskList[1], NULL, counter1, &lock);
    assert(!ret);
    printf("All threads created\n");
    ret = pthread_join(taskList[0], NULL);
    assert(!ret);
    ret = pthread_join(taskList[1], NULL);
    assert(!ret);
    printf("All threads end\n");
    pthread_mutex_destroy(&lock);
}

void* counter0(void* lock){
    while(true){
        pthread_mutex_lock((pthread_mutex_t*) lock);
        if(count >= COUNT_HALT1 && count <= COUNT_HALT2){
            printf("Thread 0 counter %d\n", count);
            count++;
        }
        pthread_mutex_unlock((pthread_mutex_t*) lock);
        if(count >= COUNT_DONE) break;
    }
    return NULL;
}

void* counter1(void* lock){
    while(true){
        pthread_mutex_lock((pthread_mutex_t*) lock);
        if(count < COUNT_HALT1 || count > COUNT_HALT2){
            printf("Thread 1 counter %d\n", count);
            count++;
        }
        pthread_mutex_unlock((pthread_mutex_t*) lock);
        if(count >= COUNT_DONE) break;
    }
    return NULL;
}