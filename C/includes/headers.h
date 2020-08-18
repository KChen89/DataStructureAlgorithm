
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


/********* Binary Tree ********/
typedef struct tree_node{
    unsigned value;
    struct tree_node * left;
    struct tree_node * right;
} TreeNode;

typedef struct BST{
    TreeNode* root;
} bst;

bool insertItem(bst* tree, int value);
bool search(bst* tree, int value);
bool deleteTreeNode(bst* tree, int value);
void traverse(bst* tree);
/******* end of binary tree *******/

#endif