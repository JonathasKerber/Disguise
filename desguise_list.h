#ifndef DESGUISE_LIST_H_
#define DESGUISE_LIST_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Node definition
struct Node;

typedef struct Node Node_t;

//List manipulation functions
int get_node_index(Node_t* node);

Node_t* create_node(int data);

void push(Node_t** list_head, Node_t* new_node);

void print(Node_t* node);

//Prompt commands
void put(int data);

Node_t* get(Node_t* node, int index);

void pull(Node_t* list_head, int index);

void clear();

Node_t* first();;

Node_t* last();

int operate_list(char *user_input);

#endif // DESGUISE_LIST_H_