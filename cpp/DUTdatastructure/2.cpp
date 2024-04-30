/*
给定一个整数数组asteroids[]，表示在同一行的行星。 
对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。
找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。
来源：力扣（LeetCode）735

堆栈操作如下，可直接调用：
 Status InitStack(Stack &S)
 Status GetTop(Stack S,int &e)
 Status Push(Stack &S, int x)
 Status Pop(Stack &S, int &x)
 Status StackEmpty(Stack S)
 
示例 1：
输入：asteroids = [5,10,-5]
输出：[5,10]
解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。

示例 2：
输入：asteroids = [8,-8]
输出：[]
解释：8 和 -8 碰撞后，两者都发生爆炸。

示例 3：
输入：asteroids = [10,2,-5]
输出：[10]
解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。

示例 4：
输入：asteroids = [10,2,-5,-20,5]
输出：[-20,5]
解释：

示例 5：
输入：asteroids = [-10,2,-5,-20,5]
输出：[-10,-5,-20,5]
解释：
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

typedef struct {
	int *base;
	int *top;	
    int stacksize;
}Stack;

Status InitStack(Stack &S)
{
	S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if(!S.base) exit(OVERFLOW);
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return OK;
}//InitStack

Status GetTop(Stack S,int &e)
{   if (S.top==S.base) return ERROR;
    e = *(S.top-1);
    return OK;
}

Status Push(Stack &S, int x)
{
	if(S.top - S.base  >= S.stacksize ) return OVERFLOW;
    *S.top++ = x;
    return OK;
}//push

Status Pop(Stack &S, int &x)
{
	 if(S.top == S.base ) return ERROR;
	 x = *(--S.top); 
	 return OK;    
}//pop

Status StackEmpty(Stack S)
{
	if(S.top == S.base ) return TRUE;
	else return FALSE;
}

 //形参分别为存行星的整型数组，数组大小 
int	 asteroidCollision(int* asteroids, int asteroidsSize){
	Stack leftStack,rightStack;
	int e;
	InitStack(leftStack);//存左行星（负值），他左侧没有右行星 
	InitStack(rightStack);//存右行星（正值），等待左行星到来 

	for(int i = 0; i < asteroidsSize; i++){
		int x = asteroids[i];
		if(x>0)
			Push(rightStack, x);
		if(x<0){
			Push(leftStack, x);
			while( !StackEmpty(leftStack) && !StackEmpty(rightStack) ){
				int neg,pos;
				GetTop(leftStack,  neg);
				GetTop(rightStack, pos);
				neg = -neg;
				if(neg == pos){
					Pop(leftStack,  e);
					Pop(rightStack, e);
				}
				else if(neg < pos)
					Pop(leftStack, e);
				else
					Pop(rightStack,e);
			}
		}
	}

	Stack ans; 
	InitStack(ans);
	while( !StackEmpty(leftStack) ){
		GetTop(leftStack, e);
		Push(ans, e);
		Pop(leftStack, e);
	}
	while( !StackEmpty(ans) ){
		GetTop(ans, e);
		printf("%d ",e);
		Pop(ans, e);
	}
	while( !StackEmpty(rightStack) ){
		GetTop(rightStack, e);
		Push(ans, e);
		Pop(rightStack, e);
	}
	while( !StackEmpty(ans) ){
		GetTop(ans, e);
		printf("%d ",e);
		Pop(ans, e);
	}
	return true;
}

int main(int argc, char** argv)
{	
	/*
	int nums[100];
    for(int i=1; i<argc; i++)
       nums[i-1] = atoi(argv[i]);
    asteroidCollision(nums,argc-1); 
    return OK;
	*/
	int nums[100];
    scanf("%d",&argc);
    for(int i=0; i<argc; i++)
    	scanf("%d",&nums[i]);
    
    asteroidCollision(nums,argc); 
    return OK;
}

