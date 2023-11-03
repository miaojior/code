#include <iostream>
#include <stdio.h>
#include <malloc.h>
typedef struct BiTNode{
char data;
struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
void CreateBT(BiTree &T)
{ char ch;
scanf("%c",&ch);
if(ch!='\n');{
  if (ch == '#') T = NULL;
  else
      { T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = ch;
        CreateBT(T->lchild);
        CreateBT(T->rchild);
      }
  }
}
void ExchangeBT(BiTree T)
{
BiTree temp;
if(T)
{ temp=T->lchild; T->lchild=T->rchild; T->rchild=temp;
ExchangeBT(T->lchild);
ExchangeBT(T->rchild);
}
}
void PreOrderTraverse(BiTree T)
{ if(T)
{ printf("%c", T->data);
PreOrderTraverse(T->lchild);
PreOrderTraverse(T->rchild);
}
}
BiTree SearchTree(BiTree T,char X)
{
BiTree bt;
if(T)
{
if(T->data==X) return T;
bt=SearchTree(T->lchild,X);
if(bt==NULL)
bt=SearchTree(T->rchild,X);
return bt;
}
return NULL;
}
int LeafCount1 (BiTree T)
{
static int count=0;
if ( T )
{ if ((T->lchild==NULL)&& (T->rchild==NULL)) count++;
else
{ count=LeafCount1( T->lchild);
count=LeafCount1( T->rchild);
}
}
return count;
}
void LeafCount2 (BiTree T, int &count)
{
  if ( T )
  { 
    if ((T->lchild==NULL)&& (T->rchild==NULL)) count++;
    LeafCount2( T->lchild, count);
    LeafCount2( T->rchild, count);
  }
}
void DispBiTree(BiTree T,int level)
{
  int i;
  if(T)
  { 
    DispBiTree(T->rchild, level + 1);
    for(i = 0; i < level;i++) printf("#");
    printf("%c\n",T->data);
    DispBiTree(T->lchild, level + 1);
  }
}
int main()
{ BiTree T,SubT;
char Subch;
int countl=0;
printf("先序序列建立二叉树\n");
CreateBT(T);

printf("\n 先序序列:");
PreOrderTraverse(T);
printf("\n 二叉树\n");
DispBiTree(T,0);
printf("交换节点左右孩子\n");
ExchangeBT(T);
printf("\n 此时二叉树为\n");
DispBiTree(T,0);
printf("要统计叶子结点个数的子树的根");
scanf("")
}