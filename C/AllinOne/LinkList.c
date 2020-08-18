#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

bool addItemDP(Node** dp, unsigned value){
    if(!(*dp)){
        (*dp) = (Node*) malloc(sizeof(Node));
        (*dp)->value = value;
        (*dp)->next = NULL;
        return true;
    }
    Node* tmp = *dp;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = (Node*) malloc(sizeof(Node));
    if(!tmp->next){
        return false;
    }
    tmp->next->value = value;
    tmp->next->next = NULL;
    return true;
}

bool addItem(LList* const list, unsigned value){
    if (!list->head){
        list->head = (Node*) malloc(sizeof(Node));
        list->head->value = value;
        list->head->next = NULL;
        list->size = 1;
        return true;
    }else{
        Node* tmp = list->head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = (Node*) malloc(sizeof(Node));
        if (!tmp->next){
            printf("Allocate mem. failed\n");
            return false;
        }
        tmp->next->value = value;
        tmp->next->next = NULL;
        ++(list->size);
        return true;
    }
    printf("Err: bool addItem() Unreachable region\n");
    return false;
}

unsigned ifHaveDP(Node* const head, unsigned value){
    Node* tmp = head;
    unsigned cnt = 0;
    while(tmp){
        if(tmp->value==value){
            cnt++;
        }
        tmp = tmp->next;
    }
    return cnt;
}

unsigned ifHave(LList* const list, unsigned value){
    Node* tmp = list->head;
    unsigned cnt = 0;
    while(tmp){
        if(tmp->value == value){
            cnt++;
        }
        tmp = tmp->next;
    }
    return cnt;
}

void traverseListDP(Node* const head){
    if(!head){
        printf("Empty list\n");
        return;
    }
    Node* tmp = head;
    while(tmp){
        printf("item: %d\n", tmp->value);
        tmp = tmp->next;
    }
}

void traverseList(LList* const list){
    Node* tmp = list->head;
    if(!tmp){
        printf("Empty list\n");
    }
    while(tmp){
        printf("item: %d \n", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void emptyListDP(Node** dp){
    Node* tmp = *dp;
    Node* prev = NULL;
    while(tmp){
        prev = tmp;
        tmp = tmp->next;
        prev->next = NULL;
        free(prev);
    }
    (*dp) = NULL;
}

void emptyList(LList* const list){
    Node * tmp = list->head;
    while(tmp){
        Node* prev = tmp;
        tmp = tmp->next;
        prev->next = NULL;
        free(prev);
    }
    list->size = 0;
    list->head = NULL;
}

unsigned deleteItemDP(Node** const dp, unsigned value){
    Node* tmp = *dp;
    Node* prev = *dp;
    unsigned cnt = 0;
    while(tmp){
        if(tmp->value==value){
            cnt++;
            if(tmp->next){
                Node* toDelete = tmp->next;
                tmp->value = toDelete->value;
                tmp->next = toDelete->next;
                toDelete->next = NULL;
                free(toDelete);
            }else{
                prev->next = NULL;
                free(tmp);
                tmp = NULL;
            }
        }else{
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return cnt;
}

unsigned deleteItem(LList* const list, unsigned value){
    Node* tmp = list->head;
    Node* prev = list->head;
    unsigned cnt = 0;
    while(tmp){
        if(tmp->value == value){
            if(tmp->next){
                tmp->value = tmp->next->value;
                Node * toDelete = tmp->next;
                tmp->next = tmp->next->next;
                toDelete->next = NULL;
                free(toDelete);
            }else{
                prev->next = NULL;
                free(tmp);
                tmp = NULL;
            }
            ++cnt;
        }else{
            prev = tmp;
            tmp = tmp->next;
        }
    }
    list->size -= cnt;
    return cnt;
}