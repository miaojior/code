int intAdjustList(LinkList L) {
    LNode *current = L->link;
    LNode *prev = L;
    int count = 0;
    while (current != NULL) {
        if (current->data % 2 == 1) {
            //LNode *temp = current;
            prev->link = current->link;
            free(current);
            current = prev->link;
        } else {
            prev = current;
            current = current->link;
            count++;
        }
    }
        prev->link = L;
    return count;
}


void outputLchild(BiTree T) {
    if (T == NULL)
        return;
    if (T->lchild != NULL)
        printf("%c ", T->lchild->data);
    outputLchild(T->lchild);
    outputLchild(T->rchild);
}