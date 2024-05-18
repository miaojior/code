typedef struct BiTNode {
    int data; // 数据类型
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

typedef struct {
    BiTree data[MAX]; // 存放二叉树节点的指针数组
    int top; // 栈顶指针
} SeqStack;

int isBST(BiTree &T){
    SeqStack s;
    s.top = -1;
    BiTree p = T;
    BiTree prev = NULL;

    while(p != NULL || s.top != -1){
        while(p != NULL){
            if(s.top == MAX - 1){
                printf("Stack overflow\n");
                return -1;
            }
            s.data[++s.top] = p;
            p = p->lchild;
        }

        if(s.top != -1){
            p = s.data[s.top--];
            // 检查当前节点的值是否小于等于前一个节点的值
            if (prev != NULL && p->data <= prev->data)
                return false;
            prev = p;
            p = p->rchild;
        }
    }
    return true;
}