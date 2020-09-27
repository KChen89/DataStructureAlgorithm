#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

bool pushStack(LStack* const sk, int value){
    if(!sk->skNode){
        sk->skNode = (Node*) malloc(sizeof(Node));
        if(!sk->skNode){
            printf("Allocate mem failed\n");
            return false;
        }
        sk->skNode->value = value;
        sk->skNode->next = NULL;
        sk->depth = 1;
        return true;
    }
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode){
        printf("Allocate mem failed\n");
        return false;
    }
    newNode->value = value;
    newNode->next = sk->skNode;
    sk->skNode = newNode;
    sk->depth++;
    return true;
}

bool popStack(LStack* const sk, int* value){
    if(!sk){
        return false;
    }
    if(!sk->skNode){
        printf("Empty stack\n");
        return false;
    }
    *value = sk->skNode->value;
    Node* tmp = sk->skNode;
    sk->skNode = sk->skNode->next;
    free(tmp);
    tmp = NULL;
    sk->depth--;
    return true;
}

void emptyStack(LStack* const sk){
    Node* tmp = sk->skNode;
    sk->skNode = NULL;
    while(tmp){
        Node* next = tmp->next;
        tmp->next = NULL;
        free(tmp);
        tmp = next;
    }
    sk->depth = 0;
}

void printStack(LStack* const sk){
    if(!sk){
        printf("Stack is empty\n");
        return;
    }
    Node* tmp = sk->skNode;
    while(tmp){
        printf("item: %d\n", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}


bool initSK(CStack** skp, int capacity){
    if(capacity<1){
        printf("Stack capacity must be larger than one\n");
        return false;
    }
    CStack* sk = (CStack*) malloc(sizeof(CStack));
    sk->stack = (int*) malloc(sizeof(int) * capacity);
    if(sk->stack == NULL){
        printf("allocate mem. failed\n");
        return false;
    }
    sk->capacity = capacity;
    sk->size = 0;
    *skp = sk;
    return true;
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
    sk->stack[sk->size++] = value;
    // sk->size++;
    printf("Push: sk->size: %d\n", sk->size);
    return true;
}

bool popSK(CStack* const sk, int* rValue){
    if(sk->size == 0){
        return false;
    }
    int tmp = sk->stack[sk->size-1];
    printf("popSK: sk->size: %d tmp: %d\n", sk->size, tmp);
    *rValue = tmp;
    sk->size--;
    return true;
}

int sizeSK(CStack* const sk){
    return sizeof(sk->stack);
}

void releaseStack(CStack* sk){
    free(sk->stack);
    sk->stack = NULL;
    free(sk);
}

void printSK(CStack* const sk){
    if(sk == NULL){
        printf("Empty Stack\n");
        return;
    }
    printf("printSK: size %ld\n", sizeof(sk->stack));
    for(int i=0;i<sk->size;i++){
        printf("Index: %d value: %d\n", i, sk->stack[i]);
    }
}

