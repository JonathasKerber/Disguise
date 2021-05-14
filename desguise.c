#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Node definition
typedef struct Node{
    int data;
    int index;
    struct Node *next;    
} Node_T;


Node_T* head;
Node_T* tail;

//List manipulation functions
void push(Node_T* head, int data){
    // Allocate memory for node
    Node_T* new_node = (Node_T*)malloc(sizeof(Node_T*));
  
    new_node->data = data;
    new_node->index = head->index++;
    new_node->next = head;
    
  
    // Change head pointer as new node is added at the beginning
    head = new_node;
}

void print(Node_T* node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

//Prompt commands
void put(int data){
    push(head, data);
}



Node_T* get(){

}

void list(){

}

void remov(){

}

void clear(){

}

Node_T* first(){

}

Node_T* last(){

}


//Main
int main(int argc, char* argv){

    head = (Node_T*)malloc(sizeof(Node_T*));
    //Node_T* tail = NULL;

    head->data = 0;
    head->index = 0;
    head->next = NULL;


    static const char delimiter[] = " \n";
    char command[15];
    char clr;
    int flag = 0;
    int input_data;
            
    //Parsing input command
    while(1){
        if(fgets(command, sizeof command, stdin)){
            printf("command %s\n", command);           
            char *ptr = strtok(command, delimiter);
            while (ptr){ 
                //Debug
                //printf("ptr %s. FLAG: %d\n", ptr, flag);
                if(flag == 1){
                    input_data = atoi(ptr);
                    printf("input_data: %d\n", input_data);
                    flag = 0;
                }else if(strcmp(ptr, "put") == 0){
                    put(input_data);                    
                    flag = 1;
                }else if(strcmp(ptr, "clear") == 0){
                    break;
                    flag = 1;    
                }else if(strcmp(ptr, "get") == 0){
                    flag = 1;    
                }else if(strcmp(ptr, "list") == 0){
                    flag = 1;    
                }else if(strcmp(ptr, "remov") == 0){
                    flag = 1;    
                }else if(strcmp(ptr, "first") == 0){
                    flag = 1;    
                }else if(strcmp(ptr, "last") == 0){
                    flag = 1;
                }else{
                    printf("Error: UNKNOWN COMMAND!\n");
                }

                ptr = strtok(NULL, delimiter);

            }                        
        }           
    }

    return 0;
}