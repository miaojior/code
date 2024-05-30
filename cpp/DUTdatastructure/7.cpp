//算法6.11　弗洛伊德算法

#include  <iostream>
using  namespace  std;

#define  MaxInt  32767                                                //表示极大值，即∞
#define  MVNum  100                                                      //最大顶点数

typedef  char  VerTexType;                                            //假设顶点的数据类型为字符型  
typedef  int  ArcType;                                                    //假设边的权值类型为整型  

int  Path[MVNum][MVNum];                                                //最短路径上顶点vj的前一顶点的序号
int  D[MVNum][MVNum];                                                //记录顶点vi和vj之间的最短路径长度

//------------图的邻接矩阵---------------
typedef  struct{  
        VerTexType  vexs[MVNum];                                        //顶点表  
        ArcType  arcs[MVNum][MVNum];                            //邻接矩阵  
        int  vexnum,arcnum;                                                //图的当前点数和边数  
}AMGraph;

int  LocateVex(AMGraph  G  ,  VerTexType  v){
        //确定点v在G中的位置
        for(int  i  =  0;  i  <  G.vexnum;  ++i)
                if(G.vexs[i]  ==  v)
                        return  i;
                return  -1;
}//LocateVex

void  CreateUDN(AMGraph  &G){  
        //采用邻接矩阵表示法，创建有向网G  
        int  i  ,  j  ,  k;
        //cout  <<"请输入总顶点数，总边数，以空格隔开:";
        cin  >>  G.vexnum  >>  G.arcnum;                                                        //输入总顶点数，总边数

        //cout  <<  "输入点的名称，如a"  <<  endl;

        for(i  =  0;  i  <  G.vexnum;  ++i){      
                //cout  <<  "请输入第"  <<  (i+1)  <<  "个点的名称:";
                cin  >>  G.vexs[i];                                                                        //依次输入点的信息  
        }
        for(i  =  0;  i  <  G.vexnum;  ++i){                                                        //初始化邻接矩阵，边的权值均置为极大值MaxInt  
                for(j  =  0;  j  <  G.vexnum;  ++j){    
                        if(j  !=  i)
                                G.arcs[i][j]  =  MaxInt;    
                        else
                                G.arcs[i][j]  =  0;
                }//for
        }//for

        //cout  <<  "输入边依附的顶点及权值，如a  b  3"  <<  endl;
        for(k  =  0;  k  <  G.arcnum;++k){                                                //构造邻接矩阵  
                VerTexType  v1  ,  v2;
                ArcType  w;
        //        cout  <<  "请输入第"  <<  (k  +  1)  <<  "条边依附的顶点及权值:";
                cin  >>  v1  >>  v2  >>  w;                                                      //输入一条边依附的顶点及权值
                i  =  LocateVex(G,  v1);    j  =  LocateVex(G,  v2);        //确定v1和v2在G中的位置，即顶点数组的下标  
                G.arcs[i][j]  =  w;                                                                //边<v1,  v2>的权值置为w  
        }//for
}//CreateUDN  

void  ShortestPath_Floyed(AMGraph  G){ 
        //本题情境下无需处理path
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++) {
            D[i][j] = G.arcs[i][j];
            if (i != j && G.arcs[i][j] < MaxInt)
                Path[i][j] = i;
            else
                Path[i][j] = -1;
        }
    for (int k = 0; k < G.vexnum; k++)
        for (int i = 0; i < G.vexnum; i++)
            for (int j = 0; j < G.vexnum; j++)
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    Path[i][j] = Path[k][j];
                }
}

void  DisplayPath(AMGraph  G  ,  int  begin  ,int  temp  ){
        //显示最短路径
        if(Path[begin][temp]  !=  -1){
                DisplayPath(G  ,  begin  ,Path[begin][temp]);
                cout  <<  G.vexs[Path[begin][temp]]  <<  "-->";
        }
}//DisplayPath

int  main(){
        //cout  <<  "************算法6.11　弗洛伊德算法**************"  <<  endl  <<  endl;
        AMGraph  G;
        char  start  ,  destination;
        int  num_start  ,  num_destination;

        CreateUDN(G);
        
        //cout  <<  "有向网G创建完成！"  <<  endl;
        
              //需要完成的函数
                ShortestPath_Floyed(G);
              //需要完成的函数

        //cout  <<  "请依次输入路径的起点与终点的名称：";
        cin  >>  start  >>  destination;
        num_start  =  LocateVex(G  ,  start);
        num_destination  =  LocateVex(G  ,  destination);

        //DisplayPath(G  ,  num_start  ,  num_destination);
        //cout  <<  G.vexs[num_destination]  <<  endl;
        cout  <<  D[num_start][num_destination]  <<  endl;
        return  0;
}//main