#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
    int key;
    struct node *lchild, *rchild;
}Node, *BST;
 
BST BSTInsect(BST root, int element){
//这里输入你的代码







}
 
int getLevel(BST root){
//这里输入你的代码







}
void inOrderTraverse(BST root){
    if(root != NULL){
        inOrderTraverse(root->lchild);
        printf("%d ", root->key);
        inOrderTraverse(root->rchild);
    }
}
 
int main(){
    int n,i,element,level;
    BST root = NULL;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &element);
        root = BSTInsect(root, element);
    }
    level = getLevel(root);
    printf("%d\n", level);
    inOrderTraverse(root);
    return 0;
}
 
 
