#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<assert.h>
#include<stddef.h>
#include<math.h>       
typedef struct LNode{ 
   int exp,coef;
   struct LNode *next;
}LNode,*LinkList;
void CreateList(LinkList &L){
   LinkList p,s,q;
   int i,temp_coef,temp_exp;
   L=(LinkList)malloc(sizeof(LNode));
   L->next=NULL;s=L;
   for(i=1;;i++)
   {
      p=(LinkList)malloc(sizeof(LNode));
      scanf("%d %d",&p->exp,&p->coef);
      p->next=NULL;s->next=p;
      s=p;
      if(p->coef==0&&p->exp==0)
      {
         free(p);
         break;
      }
      else free(p);
   }
   q=(LinkList)malloc(sizeof(LNode));
   q=L->next;
   while(q->next->coef!=0||q->next->exp!=0)
   {
      if(q->coef>q->next->coef)
      {
         temp_coef=q->coef;temp_exp=q->exp;
         q->coef=q->next->coef;q->exp=q->next->exp;
         q->next->coef=temp_coef;q->next->exp=temp_exp;
      }
      q=q->next;
   }
}
void Display(LinkList L){
   LinkList p;
   p=L->next;
   while(p->coef!=0||p->exp!=0)
   {
      if(p->coef==0)
      printf("%d ",p->exp);
      else
      printf("%dx^%d ",p->exp,p->coef);
      p=p->next;
   }
}
int main()
{
   LinkList p;
   CreateList(p);
   Display(p);
   return 0;
}