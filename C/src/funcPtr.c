#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

void Register(int interrupt_num, FuncPtr funcP){
    FuncPtrArray[interrupt_num] = funcP;
}

bool InterruptHandler(void){
    if(INTERRUPT_CODE>=MAX_INTERRUPTS){
        return false;
    }
    FuncPtrArray[INTERRUPT_CODE]();
    return true;
}

