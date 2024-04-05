void reverse(SeqList *list){
    left = 0;
    right = list->length - 1;
    while(left < right){
        temp = list->elem[left];
        list->elem[left] = list->elem[right];
        list->elem[right] = temp;
        left++;right--;
    }
}