#include <stdio.h>
#include <stdlib.h>
struct Node{    
        int data;    
        struct Node *next;    
            
        
} ;
struct Node* newNode(int data) {    
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));;   
            node->data = data;    
            node->next = NULL;
            return node;    
        }    
struct SinglyLinkedList {    
    //Represent a node of the singly linked list    
      
     
    //Represent the head and tail of the singly linked list    
     struct Node *head ;    
     struct Node *tail ;    
        
    //addNode() will add a new node to the list    
    
};
struct SinglyLinkedList* newSinglyLinkedList() {    
    struct SinglyLinkedList *list=(struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));;    
    list->head = NULL;    
    list->tail = NULL;    
    return list;    
}
struct SinglyLinkedList* addNode(struct SinglyLinkedList *linkedList,int data) {    
    //Create a new node    
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));    
    newNode->data=data;
    newNode->next=NULL;
    //Checks if the list is empty    
    if(linkedList->head == NULL) {    
        //If list is empty, both head and tail will point to new node    
        linkedList->head = newNode;    
        linkedList->tail = newNode;    
    }    
    else {    
        //newNode will be added after tail such that tail's next will point to newNode    
        // linkedList->tail->next=(struct Node*)malloc(sizeof(struct Node));
        linkedList->tail->next = newNode;    
        //newNode will become new tail of the list    
        linkedList->tail = newNode;    
    }    
    return linkedList;
}    
        
//display() will display all the nodes present in the list    
    void display(struct SinglyLinkedList *linkedList) {    
    //Node current will point to head    
    struct Node *current =   linkedList->head;    
        
    if(linkedList->head == NULL) {    
        printf("List is empty\n");
        return;    
    }    
    printf("Nodes of singly linked list: \n") ;
    while(current != NULL) {    
        //Prints each node by incrementing pointer    
        printf("%d ",current->data );
        current = current->next;    
    }    
    printf("\n"); 
}    
int main() {
    
        struct SinglyLinkedList *sList=newSinglyLinkedList();
        //Add nodes to the list    
        sList=addNode(sList,1);    
        sList=addNode(sList,2);       
        sList=addNode(sList,3);       
        sList=addNode(sList,4);      
            
        //Displays the nodes present in the list    
        display(sList);  
    return 0;
}