#include<stdio.h>
#include<stdlib.h>
#include "headers.h"
bst* BSTinit(void){
    bst* myBST = (bst*) malloc(sizeof(bst));
    if(!myBST){
        printf("Allocate mem for bst failed\n");
        return NULL;
    }
    return myBST;
}
