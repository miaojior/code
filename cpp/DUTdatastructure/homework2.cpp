23 12 3 * 2 - 4 / 34 5 * 7 + + 108 9 / +

void push(LinkStack* &top, SElemType value){
    LinkStack *newNode = new LinkStack;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

SElemType pop(LinkStack* &top){
    if(top == NULL){
        printf("栈为空，无法出栈");
        return -1;
    }
    SElemType value = top->data;
    temp = top;
    top = top->next;
    free(temp);
    return value;
}



int DecimalToOctal(int dec){
    s.top = -1;
    while(dec > 0){
        if(s.top == MAXSIZE - 1){
            printf("Stack Overflow\n");
            return -1;
        }
        s.data[++s.top] = dec%8;
        dec/=8;
    }
    octal = 0;
    while(s.top != -1)
        octal = octal*10+s.data[s.top--];
    return octal;
}



typedef struct {
    int i, j;   
    ElemType e; 
} Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int mu, nu, tu;
} TSMatrix;

TSMatrix transpose(TSMatrix M) {
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu > 0){
        for(col = 0; col < M.nu; col++)
            num[col] = 0;
        for(q = 1; q <= M.tu; q++)
            num[M.data[q].j]++;
        cpot[0] = 1;
        for(col = 1; col < T.nu; col++)
            cpot[col] = cpot[col-1] + num[col-1];
        for(q = 1; q <= M.tu; q++){
            col = M.data[q].j;
            t = cpot[col];
            T.data[t].i = M.data[q].j;
            T.data[t].j = M.data[q].i;
            T.data[t].e = M.data[q].e;
            cpot[col]++;
        }
    }
    return T;
}