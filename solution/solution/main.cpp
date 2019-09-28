//
//  main.c
//  BinarySearchTree
//
//  Created by Abhinav on 12/11/18.
//  Copyright © 2018 Abhinav. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
}*root=NULL;
 
 
 
struct Node* roots; // store address of root node
 
/*
struct Node* GetNewNode(char data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(newNode));
    (*newNode).data = data; // or Node* newNode = new BstNode;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
struct Node* tree_insert(struct Node* root, char data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
       
    }
    else if(data <= (root)->data)
    {
        (root)->left = tree_insert((root)->left,data);
    }
    else
    {
        (root)->right = tree_insert((root)->right,data);
    }
    return root;
}
 
*/
 
void tree_insert(struct Node** root, char data )
{
    struct Node* temp=*root;
    if(*root==NULL)
    {
        struct Node *treePtr=(struct Node*)malloc(sizeof(struct Node));
        *root=treePtr;
        treePtr->data=data;
        treePtr->left=NULL;
        treePtr->right=NULL;
    }
    else if(temp->data>data)
    {
        tree_insert(&(temp->left),data);
    }
    else if(temp->data<=data)
    {
        tree_insert(&(temp->right),data);
    }
}
 
 
void tree_print_sorted(struct Node* root )
{
    if (root->left != NULL)
    {
        tree_print_sorted(root->left);
    }
        printf("%c ", root->data);
       
    if (root->right != NULL)
    {
        tree_print_sorted(root->right);
       
    }
}
 
void tree_search(struct Node* root, char data)
{
   
    if(root==NULL)
    {
        printf("%c not in tree \n",data);
    }
   
    if(root->data==data)
    {
        printf("%c in tree \n",data);
    }
    if(root->data>data)
        return tree_search(root->left,data);
    if(root->data<=data)
        return tree_search(root->right,data);
}
 
 
void tree_delete(struct Node** root)
{
    if ((*root)->left != NULL)
        tree_delete(&((*root)->left));
    if ((*root)->right != NULL)
        tree_delete(&((*root)->right));
    *root=NULL;
    free(*root);
}
 
int main()
{
    struct Node* root = NULL;
    tree_insert(&root,'F');
    tree_insert(&root,'L');
    tree_insert(&root,'O');
    tree_insert(&root,'C');
    tree_insert(&root,'C');
    tree_insert(&root,'I');
    tree_insert(&root,'N');
    tree_insert(&root,'A');
    tree_insert(&root,'U');
    tree_insert(&root,'C');
    tree_insert(&root,'I');
    tree_insert(&root,'N');
    tree_insert(&root,'I');
    tree_insert(&root,'H');
    tree_insert(&root,'I');
    tree_insert(&root,'L');
    tree_insert(&root,'I');
    tree_insert(&root,'P');
    tree_insert(&root,'I');
    tree_insert(&root,'L');
    tree_insert(&root,'I');
    tree_insert(&root,'F');
    tree_insert(&root,'I');
    tree_insert(&root,'C');
    tree_insert(&root,'A');
    tree_insert(&root,'T');
    tree_insert(&root,'I');
    tree_insert(&root,'O');
    tree_insert(&root,'N');
   
   
    printf("Sorted tree is:");
    tree_print_sorted(root);
    printf("\nEnter characters to find \n");
    char char1,char2;
    scanf("%c",&char1);
    scanf("\n%c",&char2);
    tree_search(root,char1);
    tree_search(root,char2);
    tree_delete (&root);
   
    return 0;}
