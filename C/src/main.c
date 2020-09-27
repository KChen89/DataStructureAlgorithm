#include<stdio.h>
#include<stdlib.h>
#include "headers.h"
#define RANGE 10
#define SQUARE(x) (x*x)


void test(void);
bool testLinkedList(void);
bool testLinkedListDP(void);
bool testStack(void);
bool testStackNew(void);
bool testQueue(void);
bool testCbuffer(void);
bool test2Dimage(void);
void testInterrupt(void);


int main(void){
    // test();
    // if(!testLinkedListDP()){
    //     printf("test failed\n");
    // }
    // printf("Test passed\n");
    // if(!testStackNew()){
    //     printf("Test return false\n");
    // }else{
    //     printf("Test return true\n");
    // }
    // if(!testQueue()){
    //     printf("Test return false\n");
    // }else{
    //     printf("Test return true\n");
    // }
    // return 0;
    // if(!testCbuffer()){
    //     printf("Test return false\n");
    // }else{
    //     printf("Test return true\n");
    // }
    // if(!test2Dimage()){
    //     printf("Test return false\n");
    // }else{
    //     printf("Test return true\n");
    // }
    // return 0;
    // testInterrupt();
    // testThread();
    testMutex();
    return 0;
}

void test(void){
    char ySqrt;
    char y = 2;
    // y = 2;
    ySqrt = SQUARE(y++);
    printf("ySqrt = %d\n", ySqrt);
}

void ISR0(void){
    printf("ISR0 is called\n");
}

void ISR1(void){
    printf("ISR1 is called\n");
}

void ISR2(void){
    printf("ISR2 is called\n");
}

void testInterrupt(void){
    Register(0, ISR0);
    Register(1, ISR1);
    Register(2, ISR2);

    INTERRUPT_CODE = 0;
    InterruptHandler();
    INTERRUPT_CODE = 1;
    InterruptHandler();
    INTERRUPT_CODE = 2;
    InterruptHandler();
}


bool test2Dimage(void){
    unsigned height = 6;
    unsigned width = 5;
    gImg* testImg = gImgInit(height, width);

    if(!testImg){
        return false;
    }
    showImage(testImg);
    if(!setZero(testImg)){
        printf("Set zero failed\n");
        return false;
    }
    showImage(testImg);
    if(!setMax(testImg)){
        printf("Set max failed\n");
        return false;
    }
    showImage(testImg);
    freeGImg(&testImg);
    if(testImg){
        printf("Free image failed\n");
        return false;
    }
    return true;
}

bool testCbuffer(void){
    cBuf* testCb = cBufInit(RANGE);
    if(!testCb){
        return false;
    }

    for(int i=0;i<RANGE+1;i++){
        if(!pushCBuf(testCb, i)){
            printf("push failed %d\n", i);
        }
    }
    printCBuf(testCb);
    int tmp;
    for(int i=0;i<RANGE+1;i++){
        if(!popCBuf(testCb, &tmp)){
        }
    }
    if(!pushCBuf(testCb, 10)){
        return false;
    }
    printCBuf(testCb);
    // emptyCBuf(testCb);
    // printCBuf(testCb);
    freeCBuf(&testCb);
    if(testCb){
        printf("After free, buf is not NULL\n");
        return false;
    }
    return true;
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
