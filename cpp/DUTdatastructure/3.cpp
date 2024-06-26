/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为root。

除了root之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到
“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的root，返回在不触动警报的情况下，小偷能够盗取的最高金额?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii

示例1：
层次输入: root = [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7 

层次输入: root = [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9

层次输入: root = [2,1,3,null,4]
输出: 7
解释: 小偷一晚能够盗取的最高金额 3 + 4 = 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define STACK_INIT_SIZE 100
typedef int Status;
int nums[100],numno=0;

typedef struct BiTNode{
	int	data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

//输入先序序列，创建二叉树
void CreateBiTree(BiTree &T)
{	int ch;
	scanf("%d",&ch);
	if (ch ==-1) T = NULL;
	else
	{	T = (BiTNode *)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

int Value(BiTree root)
{
    if (root == NULL)
        return 0;

    int left_steal = 0, left_unsteal = 0, right_steal = 0, right_unsteal = 0;

    left_steal = Value(root->lchild);
    if (root->lchild != NULL)
        left_unsteal = Value(root->lchild->lchild) + Value(root->lchild->rchild);

    right_steal = Value(root->rchild);
    if (root->rchild != NULL)
        right_unsteal = Value(root->rchild->lchild) + Value(root->rchild->rchild);

    int steal = root->data + left_unsteal + right_unsteal;
    int unsteal = (left_steal > left_unsteal ? left_steal : left_unsteal) + (right_steal > right_unsteal ? right_steal : right_unsteal);
    return (steal > unsteal ? steal : unsteal);
}


int main()
{	BiTree T;
   	CreateBiTree(T);
	printf("%d",Value(T));
	return 1; 
}
