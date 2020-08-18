#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

CStack* initSK(int capacity){
    if(capacity<1){
        printf("Stack capacity must be larger than one\n");
        return NULL;
    }
    CStack stack;
    CStack* stackP = &stack;
    stackP->capacity = capacity;
    printf("Size of stack pointer: %d\n", sizeof(*(stackP->stack)));
    stackP->stack = (int*) malloc(sizeof(int)*capacity);
    printf("Size of stack pointer: %d\n", sizeof(*(stackP->stack)));
    stackP->size = 0;
    return stackP;
}

bool pushSK(CStack* const sk, int value){
    if(sk == NULL){
        printf("Uninitialized stack\n");
        return false;
    }
    if(sk->size >= sk->capacity){
        printf("Stack is full\n");
        return false;
    }
    sk->stack[sk->size+1] = value;
    return true;
}

int popSK(CStack* const sk){
    if()
}