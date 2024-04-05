#include <bits/stdc++.h>
#define ERROR 0

typedef struct SqList{ int *elem; int length; int listsize; }SqList;

void InsertX_B(SqList &L, int x){
    // 检查是否需要扩容
    if (L.length >= L.listsize) {
        L.elem = (int*)realloc(L.elem, (L.listsize + 1)*sizeof(int) );
        if (!L.elem)
            exit(-2);
        L.listsize++;
    }
    //二分查找
    int low = 0, high = L.length - 1;
    int pos = L.length;
    while (low <= high) {
        int mid = (low+high)/2;
        if(L.elem[mid] >= x){
            pos = mid; 
            high = mid - 1;
        }else
            low = mid + 1;
    }
    for (int i=L.length-1 ; i>=pos ; i--)
        L.elem[i+1] = L.elem[i];
    L.elem[pos] = x;
    L.length++;
}



void MergeList(ListNode* A, ListNode* B, ListNode* &C) {
    p = A->next;
    q = B->next;
    C = NULL;
    while (p && q){
        if (p->data >= q->data) {
            temp = p;
            p = p->next;
        }else{
            temp = q;
            q = q->next;
        }
        temp->next = C;
        C = temp;
    }
    while(p){
        temp = p;
        p = p->next;
        temp->next = C;
        C = temp;
    }
    while(q){
        temp = q;
        q = q->next;
        temp->next = C;
        C = temp;
    }
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = C;
    C = head;
}




   // 就地逆置链表
void reverse(ListNode *L){
    h = L->next;
    if (!h)
        printf("empty");
        return;
    prev = NULL;
    current = h;
    do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }while(current != h);
    h->next = prev;
    h = prev;
}






void ListDelete(LinkList L, int mink, int maxk) {
    if (L == NULL || L->next == NULL || mink >= maxk)
        return;
    prev = L;
    current = L->next;
    while(current && current->data < mink){
        prev = current;
        current = current->next;
    }
    while(current && current->data<=maxk){
        temp = current;
        prev->next = current->next;
        current = current->next;
        free(temp);
    }
}

typedef struct LNode {
    int exp, coef; // coef为系数, exp为指数
    struct LNode *next;
} LNode, *LinkList;

void CreateList(LinkList &pa){
    pa = (LinkList)malloc(sizeof(LNode));
    pa->next = NULL;
    while(scanf("%d%d",&coef,&exp) == 2 && (coef != 0 || exp != 0) ) {
        temp = (LNode *)malloc(sizeof(LNode));
        temp->coef = coef;
        temp->exp = exp;
        temp->next = NULL;
        q = L;
        while (q->next && q->next->exp < exp)
            q = q->next;
        temp->next = q->next;
        q->next = temp;
    }
}

void Display(LinkList L){
    p = L->next;
    while(p){
        printf("%d",p->coef);
        if(p->exp > 0)
            printf("x^%d",p->exp);
        if(p->next && p->next->coef >= 0)
            printf("+");
        p = p->next;
    }
}

int Evaluation(LinkList pa, int x){
    result = 0;
    p = L->next;
    while(p){
        result += p->coef*pow(x, p->exp);
        p = p->next;
    }
    return result;
}

void AddPoly(LinkList ha, LinkList hb){
    pa = ha->next;
    pb = hb->next;
    prev = ha;
    while(pa && pb){
        if(pa->exp < pb->exp){
            prev = pa;
            pa = pa->next;
        }else if(pa->exp > pb->exp){
            temp = (LNode *)malloc(sizeof(LNode));
            temp->coef = pb->coef;
            temp->exp = pb->exp;
            temp->next = pa;
            prev->next = temp;
            prev = prev->next;
            pb = pb->next;
        }else{
            pa->coef += pb->coef;
            if(pa->coef == 0){
                temp = pa;
                pa = pa->next;
                prev->next = pa;
                free(temp);
            }else{
                prev = pa;
                pa = pa->next;
            }
            temp = pb;
            pb = pb->next;
            free(temp);
        }
    }
    while(pb){
        temp = (LNode *)malloc(sizeof(LNode));
        temp->coef = pb->coef;
        temp->exp = pb->exp;
        temp->next = NULL;
        prev->next = temp;
        prev = prev->next;
        pb = pb->next;
    }
}