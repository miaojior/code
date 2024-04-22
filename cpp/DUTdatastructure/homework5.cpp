void InitQueue(SqQueue &Q){
    Q.base = (BiTree*)malloc(MAXQSIZE*sizeof(BiTree));
    if(!Q.base){
        printf("Queue Initialize Fail.");
        exit(0);
    }
    Q.front=Q.rear = 0;
}

bool EnQueue(SqQueue &Q, BiTree e){
    if( (Q.rear + 1) % MAXQSIZE == Q.front ){
        printf("Queue Full.");
        exit(0);
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXQSIZE;
    return true;
}

bool DeQueue(SqQueue &Q, BiTree &e){
    if( (Q.rear + 1)%MAXQSIZE == Q.front ){
        printf("Queue Empty.");
        exit(0);
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1)%MAXQSIZE;
    return true;
}

bool IsCompleteBinaryTree(BiTree root){
    if (!root)
        return true;
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, root);
    bool flag = false;
    while(Q.front != Q.rear){
        BiTree node;
        DeQueue(Q, node);
        if(node){
            if(flag)
                return false;
            EnQueue(Q, node->lchild);
            EnQueue(Q, node->rchild);
        }else
            flag = true;
    }
    return true;
}







void InitQueue(SqQueue &Q){
    Q.base = (BiTree*)malloc(MAXQSIZE*sizeof(BiTree));
    if(!Q.base){
        printf("Queue Initialize Fail.");
        exit(0);
    }
    Q.front=Q.rear = 0;
}


bool EnQueue(SqQueue &Q, BiTree e){
    if( (Q.rear + 1) % MAXQSIZE == Q.front){
        printf("Queue Full.");
        exit(0);
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXQSIZE;
    return true;
}


bool DeQueue(SqQueue &Q, BiTree &e){
    if ((Q.rear + 1) % MAXQSIZE == Q.front){
        printf("Queue Empty.");
        exit(0);
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1)%MAXQSIZE;
    return true;
}


int minDepth(BiTree root){
    if(!root) return 0;
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, root);
    int depth = 1;
    while(!Q.front == Q.rear){
        int levelSize = Q.rear-Q.front;
        for (int i = 0; i < levelSize; i++){
            BiTree node;
            DeQueue(Q, node);
            if (!node->lchild && !node->rchild)
                return depth;
            if (node->lchild)
                EnQueue(Q, node->lchild);
            if (node->rchild)
                EnQueue(Q, node->rchild);
        }
        ++depth;
    }
    return depth;
}