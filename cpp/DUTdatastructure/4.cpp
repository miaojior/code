/* 
【问题描述】
奥班农种植土豆，每年秋天都能收获很多很多，假设每个土豆能产生两个后代土豆，如何帮奥班农判断两个土豆的最近共同祖先呢，上帝曾经说过：没有两个长得一模一样的土豆

【输入形式】
二叉树的层次序列（-1表示空树，-100表示输入结束），以及两个单独的值
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define STACK_INIT_SIZE 100
#define MAXQSIZE 100
typedef int Status;

typedef struct BiTNode{
 	int	data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

typedef struct {
	BiTree *base;
	int front,rear;} SqQueue; //定义循环队列，存储Glist类型指针

void InitQueue(SqQueue &Q)
{	Q.base = (BiTree *)malloc(MAXQSIZE * sizeof(BiTree));
	Q.front = Q.rear = 0;
}

Status EnQueue(SqQueue &Q, BiTree e)
{	if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;	//队满
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q, BiTree &e)
{	if(Q.rear == Q.front) return ERROR;	//队空
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

Status QueueEmpty(SqQueue Q)
{	if(Q.rear == Q.front) return TRUE;
	else	return FALSE;
}

//输入层次序列，创建二叉树
void CreateBiTree(BiTree &T)
{	
	int data;
    scanf("%d", &data);
    if (data == -1) {
        T = NULL;
    } else {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = data;
        SqQueue Q;
        InitQueue(Q);
        EnQueue(Q, T);
        while (1) {
            BiTree p;
            DeQueue(Q, p);
            scanf("%d", &data);
            if(data != -1 && data != -100){
                p->lchild = (BiTNode *)malloc(sizeof(BiTNode));
                p->lchild->data = data;
                EnQueue(Q, p->lchild);
            }else
                p->lchild = NULL;
            scanf("%d", &data);
            if(data != -1 && data != -100){
                p->rchild = (BiTNode *)malloc(sizeof(BiTNode));
                p->rchild->data = data;
                EnQueue(Q, p->rchild);
            }else
                p->rchild = NULL;
            if(data == -100)
                break;
        }
        free(Q.base);
    }
}

//按层次遍历二叉树
void LevelOrderTraverse(BiTree T)
{	BiTree p = T;
	SqQueue Q;

	if(!T) return;
	InitQueue(Q); EnQueue(Q,p);
	while (!QueueEmpty(Q))
	{	DeQueue(Q,p);
		printf("%d ", p->data);
		if(p->lchild) EnQueue(Q,p->lchild);
		if(p->rchild) EnQueue(Q,p->rchild);
	}
}

void PreOrderTraverse(BiTree T)
{   if(T)
	{   printf("%d ", T->data);
	    PreOrderTraverse(T->lchild);
            PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{   if(T)
	{   InOrderTraverse(T->lchild);
            printf("%d ", T->data);
	    InOrderTraverse(T->rchild);
	}
}
//求两个节点的最近公共祖先
BiTree findLCA(BiTree T,int n1, int n2) {
	if(T == NULL)
        return NULL;
    if(T->data == n1 || T->data == n2)
        return T;
    BiTree leftLCA = findLCA(T->lchild, n1, n2);
    BiTree rightLCA = findLCA(T->rchild, n1, n2);
    if(leftLCA && rightLCA)
        return T;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    BiTree T;                                
	CreateBiTree(T);
	printf("\n先序序列："); PreOrderTraverse(T);

	printf("\n中序序列：");InOrderTraverse(T);                          

       printf("\n层次序列：");LevelOrderTraverse(T);
 	
       printf("\n请输入两个土豆，去找他们的最近共同祖先:");
	int n1,n2;
       scanf("%d %d",&n1,&n2);

       BiTree lca = findLCA(T, n1,n2);
    
       if (lca) 
           printf("\n最近共同祖先是：%d\n",lca->data);
       else  printf("无祖先");
    
    return 1;
}

// 二叉树例
//       1
//      / \  
//     2   3  
//    / \   \ 
//   4   5   7
//     /  
//    10 
//层次序列：1 2 3 4 5 -1 7 -1 -1 10 -100
//8 6 -1 -1 7 3 4 -100
