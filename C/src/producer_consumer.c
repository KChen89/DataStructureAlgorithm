#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"
#define NUM_PROD 5
#define NUM_CONS 5
#define MAX_NUM 10
// produce random numbers
int counter = 0;
bool done = false;
void* producer_mutex(void *arg) {
    buffer_t *buffer = (buffer_t*)arg;

    while(true) {
        if (counter>=MAX_NUM) break;
        sleep(rand() % 3);
        pthread_mutex_lock(&buffer->mutex);

        if(buffer->len == BUF_SIZE) { // full
            // wait until some elements are consumed
            printf("Producer waiting ... \n");
            pthread_cond_wait(&buffer->can_produce, &buffer->mutex);
        }

        // in real life it may be some data fetched from
        // sensors, the web, or just some I/O
        int t = rand()%10;
        printf("Produced: %d at index %d\n", t, buffer->len);
        counter++;
        // append data to the buffer
        buffer->buf[buffer->len] = t;
        buffer->len++;

        // signal the fact that new items may be consumed
        pthread_cond_signal(&buffer->can_consume);
        pthread_mutex_unlock(&buffer->mutex);
    }
    done = true;
    printf("Producer job finished\n");
    return NULL;
}

// consume random numbers
void* consumer_mutex(void *arg) {
    buffer_t *buffer = (buffer_t*)arg;

    while(true) {
        sleep(rand() % 3);
        pthread_mutex_lock(&buffer->mutex);

        if(buffer->len == 0) { // empty
            // wait for new items to be appended to the buffer
            if(done) break;
            printf("Consumer waiting ... \n");
            pthread_cond_wait(&buffer->can_consume, &buffer->mutex);
        }

        // grab data
        buffer->len--;
        printf("Consumed: %d at index %d\n", buffer->buf[buffer->len], buffer->len);
        
        // signal the fact that new items may be produced
        pthread_cond_signal(&buffer->can_produce);
        pthread_mutex_unlock(&buffer->mutex);
    }

    printf("Consumer job done\n");
    return NULL;
}

void test_PC_mutex(void) {
    buffer_t buffer = {
        .len = 0,
        .mutex = PTHREAD_MUTEX_INITIALIZER,
        .can_produce = PTHREAD_COND_INITIALIZER,
        .can_consume = PTHREAD_COND_INITIALIZER
    };

    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer_mutex, (void*)&buffer);
    pthread_create(&cons, NULL, consumer_mutex, (void*)&buffer);

    pthread_join(prod, NULL); // will wait forever
    pthread_join(cons, NULL);
}

void test_PC_semaphore(void){
    buffer_s buffer;
    buffer.len = 0;
    sem_init(&buffer.sem_lock, 0, 1);
    sem_init(&buffer.can_consume, 0, 1);
    sem_init(&buffer.can_produce, 0, 1);
    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer_semaphore, (void*)&buffer);
    pthread_create(&cons, NULL, consumer_semaphore, (void*)&buffer);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
}

void* consumer_semaphore(void* args){
    buffer_s *buffer = (buffer_s*) args;
    while(true){
        sleep(rand()%3);
        sem_wait(&buffer->sem_lock);
        if(buffer->len == 0){
            if(done) break;
            printf("Empty buffer: consumer waiting ...\n");
            sem_wait(&buffer->can_consume);
        }
        buffer->len--;
        printf("Consume %d at index %d\n", buffer->buf[buffer->len], buffer->len);
        sem_post(&buffer->sem_lock);
        sem_post(&buffer->can_produce);
    }
    printf("Producer job done\n");
    return NULL;
}

void* producer_semaphore(void* args){
    buffer_s *buffer = (buffer_s*) args;
    while(true){
        if(counter>=MAX_NUM) break;
        sleep(rand()%3);
        sem_wait(&buffer->sem_lock);
        if(buffer->len == BUF_SIZE){    
            printf("Full buffer: producer waiting ...\n");
            sem_wait(&buffer->can_produce);
        }
        int tmp = rand() % 10;
        buffer->buf[buffer->len] = tmp;
        printf("Produce %d at index %d\n", tmp, buffer->len);
        buffer->len++;
        counter++;
        sem_post(&buffer->sem_lock);
        sem_post(&buffer->can_consume);
    }
    printf("Consumer job done\n");
    return NULL;
}