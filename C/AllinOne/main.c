#include<stdio.h>
#include "headers.h"
#define RANGE 10

bool testLinkedList(void);
bool testLinkedListDP(void);

int main(void){
    if(!testLinkedListDP()){
        printf("test failed\n");
    }
    printf("Test passed\n");
    return 0;
}

bool testLinkedListDP(void){
    Node** LList = NULL;
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
