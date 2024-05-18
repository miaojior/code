void findDegree(Graphs *G, int numb, int *indegree, int *outdegree) {
    *indegree = 0;*outdegree = 0;

    ArcNode *p = G->arc[numb].firstarc;
    while(p != NULL){
        (*outdegree)++;
        p = p->link;
    }

    for(int i = 0 ; i < G->vexnum ; i++){
        p = G->arc[i].firstarc;
        while(p != NULL){
            if(p->vex == numb)
                (*indegree)++;
            p = p->link;
        }
    }
}