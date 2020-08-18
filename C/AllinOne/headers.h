
#ifndef _UTIL_H_
#define _UTIL_H_

typedef enum{
    false = 0, 
    true = 1
} bool;

typedef struct node{
    unsigned int value;
    struct node * next;
} Node;

typedef struct tree_node{
    unsigned int value;
    struct tree_node * left;
    struct tree_node * right;
} TreeNode;

typedef struct LinkedList{
    unsigned int size;
    Node* head;
} LList;


typedef struct BST{
    TreeNode* root;
} bst;

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

bool insertItem(bst* tree, int value);
bool search(bst* tree, int value);
bool deleteTreeNode(bst* tree, int value);
void traverse(bst* tree);

#endif