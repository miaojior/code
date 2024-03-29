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
typedef struct LNode {
    int exp, coef; // coef为系数, exp为指数
    struct LNode *next;
} LNode, *LinkList;

/* 创建单链表存放一元多项式 */
void CreateList(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    int coef,exp;
    while(scanf("%d%d",&coef,&exp) == 2 && (coef != 0 || exp != 0) ) {
        LNode *temp = (LNode *)malloc(sizeof(LNode));
        temp->coef = coef;
        temp->exp = exp;
        temp->next = NULL;
        // 找到合适的位置插入节点，使得指数从小到大
        LNode *q = L;
        while (q->next && q->next->exp < exp)
            q = q->next;
        temp->next = q->next;
        q->next = temp;
    }
}

/* 遍历单链表,格式化输出一元多项式的每一项 */
void Display(LinkList L){
    LNode *p = L->next;
    while(p){
        printf("%d",p->coef);
        if(p->exp > 0)
            printf("x^%d",p->exp);
        if(p->next && p->next->coef >= 0)
            printf("+");
        p = p->next;
    }
}

/* 一元多项式求值 */
double Value(LinkList L, int x){
    double result = 0;
    LNode *p = L->next;
    while(p){
        result += p->coef*pow(x, p->exp);
        p = p->next;
    }
    return result;
}

/* 删除一元多项式中的指定项 */
void DeleteElem(LinkList &L, int e) {
    LNode *p = L;
    while(p->next && p->next->exp != e)
        p = p->next;
    if(p->next){
        LNode *temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

// ha = ha + hb 
void AddPoly(LinkList ha, LinkList hb){
    LNode *pa = ha->next;
    LNode *pb = hb->next;
    LNode *prev = ha;
    while(pa && pb){
        if(pa->exp < pb->exp){
            prev = pa;
            pa = pa->next;
        }else if(pa->exp > pb->exp){
            // 在ha中插入hb中当前节点的副本
            LNode *temp = (LNode *)malloc(sizeof(LNode));
            temp->coef = pb->coef;
            temp->exp = pb->exp;
            temp->next = pa;
            prev->next = temp;
            prev = prev->next;
            pb = pb->next;
        }else{
            // 指数相同，系数相加,系数为0，删除节点
            pa->coef += pb->coef;
            if(pa->coef == 0){
                LNode *temp = pa;
                pa = pa->next;
                prev->next = pa;
                free(temp);
            }else{
                prev = pa;
                pa = pa->next;
            }
            LNode *temp = pb;
            pb = pb->next;
            free(temp);
        }
    }
    //hb中仍然存在余项，直接接在ha末尾
    while(pb){
        LNode *temp = (LNode *)malloc(sizeof(LNode));
        temp->coef = pb->coef;
        temp->exp = pb->exp;
        temp->next = NULL;
        prev->next = temp;
        prev = prev->next;
        pb = pb->next;
    }
}

int main() {
    LinkList ha, hb;
    int x;
    double val;

    scanf("%d", &x); // 读入x

    CreateList(ha); // 创建单链表ha存放一元多项式
    printf("ha = ");
    Display(ha); // 遍历单链表输出一元多项式
    val = Value(ha, x);
    printf("=%f\n", val);

    CreateList(hb); // 创建单链表hb存放一元多项式
    printf("hb = ");
    Display(hb); // 遍历单链表输出一元多项式
    val = Value(hb, x);
    printf("=%f\n", val);

    AddPoly(ha, hb); // ha = ha + hb
    printf("ha+hb = ");
    Display(ha);
    val = Value(ha, x);
    printf("=%f\n", val);

    scanf("%d", &x); // 读入待删除的多项式指数项
    DeleteElem(ha, x);
    Display(ha);

    return OK;
}