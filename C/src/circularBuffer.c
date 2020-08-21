#include<stdio.h>
#include<stdlib.h>
#include"headers.h"


cBuf* cBufInit(const int capacity){
    if(capacity<1){
        printf("Capacity cannot be less than 1\n");
        return NULL;
    }
    // cb = (cBuf*) malloc(sizeof(cBuf));
    // if(!cb){
    //     printf("Allocate mem for cBuf. failed\n");
    //     return false;
    // }
    cBuf* cb = (cBuf*) malloc(sizeof(cBuf));
    if(!cb){
        printf("Allocate mem for cBuf failed\n");
        return NULL;
    }
    cb->buf = (int*) malloc(sizeof(int) * capacity);
    if(!cb->buf){
        printf("Allocate mem for buf failed\n");
    }
    for(int i=0;i<capacity;i++){
        cb->buf[i] = 0;
    }
    printf("sizeof cbuf: %ld\n", sizeof(cb));
    cb->capacity = capacity;
    cb->head = cb->capacity-1;
    cb->tail = 0;
    cb->size = 0;
    return cb;
}


bool pushCBuf(cBuf* const cb, const int value){
    if(!cb || !cb->buf){
        printf("Uninitialized Buffer\n");
        return false;
    }
    if(cb->size>=cb->capacity){
        printf("Buffer is full\n");
        return false;
    }
    cb->head++;
    if(cb->head>=cb->capacity){
        cb->head -= cb->capacity;
    }
    cb->buf[cb->head] = value;
    cb->size++;
    return true;
}

bool popCBuf(cBuf* cb, int* value){
    if(!cb || !cb->buf){
        printf("Uninitialized buf\n");
        return false;
    }
    if(cb->size==0){
        printf("Empty buf\n");
        return false;
    }
    *value = cb->buf[cb->tail];
    cb->buf[cb->tail] = 0;
    cb->tail++;
    cb->size--;
    return true;
}

void printCBuf(cBuf* const cb){
    if(!cb || !cb->buf){
        printf("Buf is empty\n");
        return;
    }
    for(int i=0;i<cb->capacity;i++){
        printf("Index: %d value: %d\n", i, cb->buf[i]);
    }
}

void emptyCBuf(cBuf* const cb){
    if(!cb || !cb->buf){
        printf("Buf is empty\n");
        return;
    }
    for(int i=0;i<cb->capacity;i++){
        cb->buf[i] = 0;
    }
    cb->size = 0;
    cb->head = cb->capacity-1;
    cb->tail = 0;
}

void freeCBuf(cBuf** cbP){
    free((*cbP)->buf);
    *cbP = NULL;
}