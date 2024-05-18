typedef struct ArcNode{
    int vex;
    struct ArcNode *link;
    //InfoType *info;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarcl;
}Vnode;

typedef struct{
    VNode arc[MAXSIZE];
    int vexnum,arcnum;
    int kind;
}Graphs;
void DFSForest(Graph G, CSTree &T)
{   
    T=NULL;
    for(v=0;v<G.vexnum;++v)
        visited[v]=0;
    for(v=0; v<G.vexnum;++v) 
    if(!visited[v]){
        s=(CSTree)malloc(sizeof(CSNode));
        s->data=G.arc[v].data;
        s->fc=NULL;
        s->nb=NULL;
        if(!T)
            T=s;
        else
            q->nb=s;
        q=s;
        DFSTree(G, v, s);
    }
 }
 

void DFSTree(Graph G,int v,CSTree &T){
    visited[v]=1;
    first=true;
    for(p=G.arc[v].firstarc;p!=NULL;p=p->link){
        w=p->vex
        if(!visited[w]){
            s=(CSTree)malloc(sizeof(CSNode));
            s->data=G.arc[w].data;
            s->fc=NULL;s->nb=NULL;
            if(first){
                T->fc=s;
                first=FALSE;
            }else
                T->nb=s;
            T=S;
            DFSTree(G,w,T);
        }
}

