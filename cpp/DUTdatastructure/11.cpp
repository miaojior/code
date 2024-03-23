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
void CreateList(LinkList &L) {
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LNode *p = L;
    int coef, exp;
    while (scanf("%d%d", &coef, &exp) == 2 && (coef != 0 || exp != 0)) {
        LNode *temp = (LNode *)malloc(sizeof(LNode));
        temp->coef = coef;
        temp->exp = exp;
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
}

/* 遍历单链表,格式化输出一元多项式的每一项 */
void Display(LinkList L) {
    LNode *p = L->next;
    while (p) {
        printf("%d", p->coef);
        if (p->exp > 0) {
            printf("x^%d", p->exp);
        }
        if (p->next && p->next->coef >= 0) {
            printf("+");
        }
        p = p->next;
    }
}

/* 一元多项式求值 */
double Value(LinkList L, int x) {
    double result = 0;
    LNode *p = L->next;
    while (p) {
        result += p->coef * pow(x, p->exp);
        p = p->next;
    }
    return result;
}

/* 删除一元多项式中的指定项 */
void DeleteElem(LinkList &L, int e) {
    LNode *p = L;
    while (p->next && p->next->exp != e) {
        p = p->next;
    }
    if (p->next) {
        LNode *temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

// ha = ha + hb 
void AddPoly(LinkList ha, LinkList hb) {
    LNode *p = ha;
    while (p->next) {
        p = p->next;
    }
    p->next = hb->next;
    free(hb);
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