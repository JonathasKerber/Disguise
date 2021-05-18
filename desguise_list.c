#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "desguise_list.h"

//Node definition
struct Node{
    int data;
    int index;
    struct Node *next;
    struct Node *previous;
};

typedef struct Node Node_t;

Node_t* head = NULL;
Node_t* tail = NULL;

//List manipulation functions
int get_node_index(Node_t* node){
    if(node == NULL){
        return 0;
    }else{
        return node->index;
    }
}

Node_t* create_node(int data){
    int index;
    Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));

    index = get_node_index(head);
    //printf("index: %d\n", index);

    new_node->data = data;
    new_node->next = NULL;
    new_node->previous = NULL;
    new_node->index = index+=1;    
    return new_node;
}

void push(Node_t** list_head, Node_t* new_node){    
    new_node->next = *list_head;    
    //printf("1 new_node->next:%d\n", new_node->next);
    if((*list_head) != NULL){
        (*list_head)->previous = new_node;
        //printf("2.1 new_node->next->previous:%d\n", new_node->next->previous);
    }
    (*list_head) = new_node;
    //printf("3 list_head:%d\n", *list_head);
}

void print(Node_t* node){     
    Node_t* tmp = node;
    //printf("Starting listing: ");
    while(tmp != NULL){
        //printf("\tdata:%d index:%d", tmp->data, tmp->index);
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");    
    //printf("Listing finished.\n");
    free(tmp);
}

//Prompt commands
void put(int data){
    Node_t* new_node = create_node(data);
    push(&head, new_node);
}

Node_t* get(Node_t* node, int index){
    Node_t* tmp = (Node_t*)malloc(sizeof(Node_t));
    tmp = node;

    while(tmp != NULL){             
        if(tmp->index == index){
            return tmp;
        }else{
            tmp = tmp->next;
        }     
    }    
    return tmp;
}

void pull(Node_t* list_head, int index){
    Node_t* tmp_1 = (Node_t*)malloc(sizeof(Node_t));
    Node_t* tmp_2 = (Node_t*)malloc(sizeof(Node_t));
    tmp_1 = get(list_head, index);
    
    if(tmp_1 != NULL){
        if(tmp_1->previous != NULL){            
            tmp_1->previous->next = tmp_1->next;            
            //Updating indexes
            tmp_2 = tmp_1;
            while(tmp_2->previous != NULL){
                tmp_2->previous->index-=1;
                tmp_2 = tmp_2->previous;
            } 
        }else{
            tmp_1 = tmp_1->next;
        }
        free(tmp_1);
    }  
}


void clear(Node_t** list_head){    
    Node_t* tmp = (Node_t*)malloc(sizeof(Node_t));
    
    while((*list_head) != NULL){
        tmp = *list_head;    
        (*list_head) = (*list_head)->next;
        free(tmp);
    }
}

Node_t* first(){
    if(head != NULL){
        printf("%d\n", head->data);        
    }
    return head;    
}

Node_t* last(){

}


//Main function to operate list
int operate_list(char *user_input){
    Node_t* tmp_node = (Node_t*)malloc(sizeof(Node_t));

    static const char delimiter[] = " \n";    
    char command[10];
    char clr;
    int flag = 0;
    int input_data;
    int control = 1;                
                     
    char *ptr = strtok(user_input, delimiter);      
    while (ptr){                
        //printf("\tptr %s. FLAG: %d\n", ptr, flag);
        if(flag == 0){                    
            strcpy(command, ptr);            
            flag = 1;                    
        }else {
            input_data = atoi(ptr);            
        }
        ptr = strtok(NULL, delimiter);
    }        

    flag = 0;
    
    if(strcmp(command, "put") == 0){
        put(input_data);
    }else if(strcmp(command, "clear") == 0){                    
        clear(&head);                
    }else if(strcmp(command, "get") == 0){
        tmp_node = get(head, input_data);
        //If a given node item doesn't exist, get() will return NULL
        //and the user will receive -1 as a return for his search
        if(tmp_node == NULL){
            printf("%d\n", -1);
        }else{
            printf("%d\n", tmp_node->data);
        }                
    }else if(strcmp(command, "list") == 0){
        print(head);
    }else if(strcmp(command, "remove") == 0){
        pull(head, input_data);
    }else if(strcmp(command, "first") == 0){
        first();
    }else if(strcmp(command, "last") == 0){
        print(head);
    }

    return 0;
}