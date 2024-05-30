#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
    int key;
    struct node *lchild, *rchild;
}Node, *BST;
//修复了二叉bug（昆虫)树
//BST BSTInsect(BST root, int element)
BST BSTInsert(BST root, int element){
    //这里输入你的代码
    if (root == NULL) {
        root = (Node *)malloc(sizeof(Node));
        root->key = element;
        root->lchild = root->rchild = NULL;
    }else if(element < root->key)
        root->lchild = BSTInsert(root->lchild, element);
    else
        root->rchild = BSTInsert(root->rchild, element);
    return root;
}
 
int getLevel(BST root){
    if (root == NULL)
        return 0;
    int leftLevel = getLevel(root->lchild);
    int rightLevel = getLevel(root->rchild);
    return (leftLevel > rightLevel ? leftLevel : rightLevel) + 1;
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
        root = BSTInsert(root, element);
    }
    level = getLevel(root);
    printf("%d\n", level);
    inOrderTraverse(root);
    return 0;
}
 
 
