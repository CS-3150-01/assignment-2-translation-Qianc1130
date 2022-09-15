#include <stdio.h>
#include <stdlib.h>
struct Node{    
        int data;    
        struct Node *left;    
        struct Node *right;    
             
    //Represent the root of binary tree       
     
};
struct BinarySearchTree{
    struct Node root;
};

struct Node* newNode(int data){    
            //Assign data to the new node, set left and right children to null    
            struct Node *node=(struct Node*)malloc(sizeof(struct Node));
            node->data = data;
            node->left = NULL;   
            node->right = NULL;
            return node;
}

    //factorial() will calculate the factorial of given number    
int factorial(int num) {    
    int fact = 1;    
    if(num == 0)    
        return 1;    
    else {    
        while(num > 1) {    
            fact = fact * num;    
            num--;    
        }    
        return fact;    
    }    
}    
//numOfBST() will calculate the total number of possible BST by calculating Catalan Number for given key    
int numOfBST(int key) {    
    int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key));    
    return catalanNumber;    
}    
     
int main() {
    //struct Node* xxx=newNode(123);
    // printf("xxx->data: %d\n",xxx->data);
    struct BinarySearchTree *bt = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));    
    //Display total number of possible binary search tree with key 5    
    printf("Total number of possible Binary Search Trees with given key: %d\n" , numOfBST(5) );
    return 0;
}