#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *left;
    struct Node *rigth;
};

struct Node* CreateNode(int value){
    struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
    tempNode->value = value;
    tempNode->left = NULL;
    tempNode->rigth = NULL;
    return tempNode;
}

struct Node* InsertValue(struct Node* node, int value){
    if(node == NULL){ 
        return CreateNode(value);
    }
    if(node->value > value){
        node->left = InsertValue(node->left, value);
    }
    else if(node->value < value){
        node->rigth = InsertValue(node->rigth, value);
    }
    return node;
}

struct Node* FindValue(struct Node* node, int value){
    if(node == NULL || node->value == value) return node;
    
    if(node->value > value) return FindValue(node->left, value);
    return FindValue(node->rigth, value);

}

void InOrderPrint(struct Node* node){
    if(node != NULL){
        InOrderPrint(node->left);
        printf("%d ", node->value);
        InOrderPrint(node->rigth);
    }
}

void PreOrderPrint(struct Node* node){
    if(node != NULL){
        printf("%d ", node->value);
        PreOrderPrint(node->left);
        PreOrderPrint(node->rigth);
    }
}

void PosOrderPrint(struct Node* node){
    if(node != NULL){
        PosOrderPrint(node->left);
        PosOrderPrint(node->rigth);
        printf("%d ", node->value);
    }
}

int main()
{
    struct Node *root = NULL;
    
    root = InsertValue(root, 10);
    InsertValue(root, 11);
    InsertValue(root, 12);
    InsertValue(root, 14);
    InsertValue(root, 17);
    InsertValue(root, 13);
    InsertValue(root, 16);
    InsertValue(root, 15);
    
    // printf("Pre order: \n");
    // PreOrderPrint(root);
    // printf("\nIn order: \n");
    // InOrderPrint(root);
    // printf("\nPos order: \n");
    // PosOrderPrint(root);
    
    // if(FindValue(root, 19) != NULL){
    //     printf("was found\n");
    // } else {
    //     printf("wasn't found\n");
    // }
    
    
    return 0;
}
