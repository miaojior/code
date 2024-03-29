/* 一元多项式表示*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;

/* 链表结点定义 */
typedef struct LNode{
    int exp, coef; //coef为指数, exp为系数
    struct LNode *next;
}LNode, *LinkList;

/* 创建单链表存放一元多项式*/
void CreateList(LinkList &L)
{//这里输入你的代码     







 }  
//遍历单链表,格式化输出一元多项式的每一项
void Display(LinkList L)
{     
//在这里插入你的代码







}

/* 一元多项式求值 */
double Value(LinkList L, int x)
{  
//在这里插入你的代码







}/* 一元多项式求值 */

/*删除一元多项式中的指定项 */
void DeleteElem(LinkList &L, int e)
{     
//在这里插入你的代码







}//DeleteElem

//ha = ha + hb 
void  AddPoly(LinkList ha,LinkList hb)
{  //在这里插入你的代码
 






} 

Status main()
{
    LinkList ha,hb;
    int x;
    double val; 

    scanf("%d",&x); //读入x

    CreateList(ha);//创建单链表ha存放一元多项式
    printf("ha = ");
    Display(ha);   //遍历单链表输出一元多项式
    val = Value(ha, x);
    printf("=%f\n",val);  

    CreateList(hb);//创建单链表hb存放一元多项式
    printf("hb = ");
    Display(hb);   //遍历单链表输出一元多项式
    val = Value(hb, x);
    printf("=%f\n",val);  

    AddPoly(ha,hb);//ha = ha + hb 
    printf("ha+hb = ");
    Display(ha);
    val = Value(ha, x);
    printf("=%f\n",val);  

    scanf("%d",&x); //读入待删除的多项式指数项
    DeleteElem(ha,x);
    Display(ha);

    return OK;
}
