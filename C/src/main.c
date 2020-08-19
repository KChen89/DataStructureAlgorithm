#include<stdio.h>
#include<stdlib.h>
#include "headers.h"
#define RANGE 10

bool testLinkedList(void);
bool testLinkedListDP(void);
bool testStack(void);
bool testStackNew(void);
bool testQueue(void);

int main(void){
    // if(!testLinkedListDP()){
    //     printf("test failed\n");
    // }
    // printf("Test passed\n");
    // if(!testStackNew()){
    //     printf("Test return false\n");
    // }else{
    //     printf("Test return true\n");
    // }
    if(!testQueue()){
        printf("Test return false\n");
    }else{
        printf("Test return true\n");
    }
    return 0;
}

bool testQueue(void){
    LQueue testQ = {.qNode = NULL, .size=0};
    LQueue* testQp = &testQ;
    for(int i=0;i<RANGE;i++){
        if(!pushQ(testQp, i)){
            printf("Pushs Queue failed %d\n", i);
            return false;
        }
    }
    printQ(testQp);
    // int tmp=-1;;
    // for(int i=0;i<RANGE+1;i++){
    //     if(!popQ(testQp, &tmp)){
    //         printf("Pop Queue failed %d\n", i);
    //         return false;
    //     }
    //     printf("Pop Q at %d -> %d\n", i, tmp);
    // }
    // for(int i=0;i<RANGE;i++){
    //     if(!pushQ(testQp, i)){
    //         printf("Pushs Queue failed %d\n", i);
    //         return false;
    //     }
    // }
    emptyQ(testQp);
    printQ(testQp);
    return true;
}

bool testStackNew(void){
    LStack testStack = {.depth = 0, .skNode = NULL};
    LStack* testStackP = &testStack;
    for(int i=0;i<RANGE;i++){
        if(!pushStack(testStackP, i)){
            printf("Push %d failed\n", i);
            return false;
        }
    }
    printStack(testStackP);
    int tmp;
    for(int i=0;i<RANGE+1;i++){
        if(!popStack(testStackP, &tmp)){
            printf("Pop failed %d\n", i);
        }else{
            printf("i: %d Pop out %d\n", i, tmp);
        }
    }
    printStack(testStackP);
    for(int i=0;i<RANGE;i++){
        if(!pushStack(testStackP, i)){
            printf("Push %d failed\n", i);
            return false;
        }
    }
    printStack(testStackP);
    emptyStack(testStackP);
    printStack(testStackP);
    return true;
}

bool testStack(void){
    CStack** skp = (CStack**) malloc(sizeof(CStack**));
    if(!initSK(skp, RANGE)){
        return false;
    }
    CStack* testSK = *skp;
    int tmp;
    bool result;
    for(int i=0; i<RANGE+1; i++){
        result = pushSK(testSK, i);
        if(result==false){
            printf("Push failed %d\n", i);
        }
    }
    // printSK(testSK);
    for(int i=0;i<RANGE+1;i++){
        if(!popSK(testSK, &tmp)){
            printf("Pop element failed %d\n", i);
        }else{
            printf("Returned element at i=%d is %d\n", i, tmp);
        }
    }

    return 0;
}

bool testLinkedListDP(void){
    Node** LList = malloc(sizeof(Node**));
    Node* head = NULL;
    LList = &head;
    for (int i=0;i<RANGE;i++){
        if(!addItemDP(LList, i)){
            printf("Additem failed i: %d\n", i);
            return false;
        }
    }
    // traverseListDP(*LList);
    for (int i=0;i<RANGE;i++){
        if(!addItemDP(LList, i)){
            printf("Additem failed i: %d\n", i);
            return false;
        }
    }
    traverseListDP(*LList);
    // printf("Empty list\n");
    // emptyListDP(LList);
    // printf("Traverse list again\n");
    // traverseListDP(*LList);
    unsigned cnt;
    cnt = deleteItemDP(LList, 0);
    printf("%d 0 exist\n", cnt);
    traverseListDP(*LList);
    cnt = deleteItemDP(LList, 9);
    printf("%d 9 exist\n", cnt);
    traverseListDP(*LList);
    return true;
}

bool testLinkedList(void){
    LList* testLList;
    LList tList = {.size = 0, .head = NULL};
    // printf("init tList %p\n", tList.head);
    testLList = &tList;
    for(int i=0;i<RANGE;i++){
        if(!addItem(testLList, i)){
            printf("Error: cannot addItem i=%d\n", i);
            return false;
        }
    }
    for(int i=0;i<RANGE;i++){
        if(!addItem(testLList, i)){
            printf("Error: cannot addItem i=%d\n", i);
            return false;
        }
    }
    printf("list size: %d\n", testLList->size);
    traverseList(testLList);
    // emptyList(testLList);
    // printf("Traverse again\n");
    // traverseList(testLList);
    unsigned cnt;
    printf("Deletet 0\n");
    cnt = deleteItem(testLList, 0);
    printf("%d 0 exist\n", cnt);
    traverseList(testLList);
    printf("Deletet 9\n");
    cnt =  deleteItem(testLList, 9);
    printf("%d 9 exist\n", cnt);
    traverseList(testLList);
    return true;
}