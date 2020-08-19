#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

bool pushQ(LQueue* const Lq, int value){
    if(!Lq){
        printf("Uninitialized queue\n");
        return false;
    }
    if(!Lq->qNode){
        Lq->qNode = (Node*) malloc(sizeof(Node));
        if(!Lq->qNode){
            return false;
        }
        Lq->size = 1;
        Lq->qNode->next = NULL;
        return true;
    }
    Node* tmp = Lq->qNode;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = (Node*) malloc(sizeof(Node));
    if(!tmp->next){
        return false;
    }
    tmp->next->value = value;
    tmp->next->next = NULL;
    Lq->size++;
    return true;
}

bool popQ(LQueue* Lq, int* value){
    if(!Lq){
        printf("Uninitialized queue\n");
        return false;
    }
    if(!Lq->qNode){
        printf("Empty queue\n");
        return false;
    }
    Node* tmp = Lq->qNode;
    *value = tmp->value;
    Lq->qNode = tmp->next;
    tmp->next = NULL;
    free(tmp);
    Lq->size--;
    return true;
}

void emptyQ(LQueue* Lq){
    if(!Lq){
        return;
    }
    Node* tmp = Lq->qNode;
    Node* prev = NULL;
    while(tmp->next){
        prev = tmp;
        tmp  = tmp->next;
        prev->next = NULL;
        free(prev);
    }
    Lq->size = 0;
}

void printQ(LQueue* Lq){
    if(!Lq){
        return;
    }
    Node* tmp = Lq->qNode;
    while(tmp){
        printf("Q: %d\n", tmp->value);
        tmp = tmp->next;
    }
    return;
}