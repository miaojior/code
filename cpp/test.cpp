#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{        ElemType data;
         struct node *link;
}LNode,*LinkList;

void InsertAtHead(LinkList &La,int n)
{
	LinkList p;
	int i;
	La=(LinkList)malloc(sizeof(LNode));
	La->data=0;
	La->link=NULL;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->link=La->link;
		La->link=p;
	}
}

void InsertAtTail(LinkList &Lb,int m)
{
	LinkList p,s;
	int i;
	Lb=(LinkList)malloc(sizeof(LNode));
	Lb->data=0;
	Lb->link=NULL;
	s=Lb;
	for(i=0;i<m;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->link=NULL;
		s->link=p;
		s=p;
	}
}
void PrintList(LinkList L)
{
	    LinkList p=L->link;
		printf("H->");
		while(p->link)
		{
			printf("%d->",p->data);
			p=p->link;
		}
		printf("%d\n",p->data);
}

void ReverseList(LinkList La)
{
	LinkList p=La->link,q=La->link->link,u;
	p->link=NULL;
	while(q)
	{
		u=q->link;
		q->link=La->link;
		La->link=q;
		q=u;
	}
}

void MergeList(LinkList La,LinkList Lb,LinkList &Lc)
{	LinkList pa=La->link,pb=Lb->link,pc;
    Lc=pc=La;
    while(pa&&pb)
    {
         if(pa->data<pb->data)
           {
             pc->link=pa;
             pc=pa;
             pa=pa->link;
           }
      else if(pa->data==pb->data)
      {
        pc->link=pa;
        pc=pa;
        pa=pa->link;
        pb=pb->link;
}
else{
pc->link=pb;
pc=pb;
pb=pb->link;
}
}
pc->link=pa?pa:pb;
free(Lb);
}

void DelOdd(LinkList Lc)
{ LinkList p=Lc->link,pre=Lc;
   while(p)
  { 
    if(p->data%2)
         { pre->link=p->link;
           free(p);
           p=pre->link;
         }
    else
     { pre=p;
        p=p->link;
     }
   }
}
int main()
{ LinkList La,Lb,Lc;
int n,m;
printf("请输入单链表 La 的结点数: ");
scanf("%d",&n);
InsertAtHead(La,n);
printf("建立的单链表 La 为：\n");
PrintList(La);
printf("请输入单链表 Lb 的结点数: ");
scanf("%d",&m);
InsertAtTail(Lb,m);
printf("建立的单链表 Lb 为：\n");
PrintList(Lb);
ReverseList(La);
printf("逆置后的单链表 La 为：\n");
PrintList(La);
MergeList(La,Lb,Lc);
printf("将 La 和 Lb 合并后的升序单链表 Lc 为：\n");
PrintList(Lc);
DelOdd(Lc);
printf("删除数据域值为奇数的元素后单链表 Lc 为：\n");
PrintList(Lc);
}