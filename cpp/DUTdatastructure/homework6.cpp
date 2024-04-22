int countRightTree(BiTree T){
    int count = 0;
    while(T != NULL){
        count++;
        T = T->rchild;
    }
    return count;
}



void invertTree(BiTree &T){
    if (T == NULL)
        return;
    invertTree(T->lchild);
    invertTree(T->rchild);
    //swap
    BiTree tmp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = tmp;
}

