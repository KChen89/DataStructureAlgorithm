
#ifndef _UTIL_H_
#define _UTIL_H_

typedef enum{
    false = 0, 
    true = 1
} bool;

/******** Linked List *********/
typedef struct node{
    unsigned value;
    struct node * next;
} Node;

typedef struct LinkedList{
    unsigned size;
    Node* head;
} LList;

bool addItemDP(Node** dp, unsigned value);

bool addItem(LList* const list, const unsigned value);

unsigned ifHave(LList * const list, const unsigned value);

unsigned ifHaveDP(Node* const head, unsigned value);

unsigned deleteItem(LList * const list, const unsigned value);

unsigned deleteItemDP(Node** const dp, unsigned value);

void traverseList(LList* const list);

void traverseListDP(Node* const head);

void emptyList(LList * list);

void emptyListDP(Node** dp);
/****** end of linked list ******/

/*** circular buffer ***/
typedef struct Cbuffer{
    int* buf;
    int capacity;
    int head;
    int tail;
    int size;
} cBuf;

cBuf* cBufInit(const int capacity);
bool pushCBuf(cBuf* const cb, const int value);
bool popCBuf(cBuf* const cb, int* value);
void printCBuf(cBuf* const cb);
void emptyCBuf(cBuf* const cb);
void freeCBuf(cBuf** cbP);
/***  end of circular buffer ***/

/*** queue (FIFO) ***/
typedef struct queue{
    unsigned size;
    Node* qNode;
} LQueue;

bool pushQ(LQueue* const Lq, int value);
bool popQ(LQueue* const Lq, int* value);
void emptyQ(LQueue* const Lq);
void printQ(LQueue* const Lq);

/*** end of queue ***/
/** stack (FILO) **/
typedef struct stack{
    unsigned size;
    unsigned capacity;
    int* stack;
} CStack;

bool initSK(CStack** sk, int capacity);

bool pushSK(CStack* const sk, int value);

bool popSK(CStack* const sk, int* rValue);

int sizeSK(CStack* const sk);

void emptySK(CStack* const sk);

void printSK(CStack* const sk);

typedef struct stackList{
    unsigned depth;
    Node* skNode;
} LStack;

bool pushStack(LStack* const sk, int value);
bool popStack(LStack* const sk, int* value);
void emptyStack(LStack* const sk);
void printStack(LStack* const sk);
/******** end of stack *******/

/********* Binary Tree ********/
typedef struct tree_node{
    int value;
    struct tree_node * left;
    struct tree_node * right;
} TreeNode;

typedef struct BST{
    TreeNode* root;
} bst;

bst* BSTinit(void);
bool insertItem(bst* tree, int value);
bool search(bst* tree, int value);
bool deleteTreeNode(bst* tree, int value);
void traverse(bst* tree);
/******* end of binary tree *******/

/*** 2-D image ***/
typedef unsigned char PIXEL;

typedef struct{
    unsigned height;
    unsigned width;
    PIXEL** matrix;
} gImg;

gImg* gImgInit(const unsigned height, const unsigned width);
bool setValue(gImg* const image, const unsigned y, const unsigned x, PIXEL value);
bool getValue(gImg* const image, const unsigned y, const unsigned x, PIXEL* value);
void showImage(gImg* const image);
bool setZero(gImg* const image);
bool setMax(gImg* const image);
void freeGImg(gImg** gIP);
/*** end of 2-D image ***/

/*** pointer to functions ***/
#define MAX_INTERRUPTS 8
typedef void (*FuncPtr)(void);
FuncPtr FuncPtrArray[MAX_INTERRUPTS];
unsigned char INTERRUPT_CODE;
void Register(int interrupt_num, FuncPtr funcP);
bool InterruptHandler(void);
/*** end of pointer to functions ***/

#endif