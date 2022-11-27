#include "ALGraph.h"
int visited[MaxSize];//为全局标志数组
template<class T>
ALGraph<T>::ALGraph(T *a, int n) {//有参构造函数
    vertexNum = n;//顶点数
    edgeNum = 0;//边数
    for(int i = 0;i<vertexNum;i++)
    {
        adjlist[i].vertex = a[i];
        adjlist[i].firstedge = NULL;
    }
}

template<class T>
void ALGraph<T>::DFSL(int v) {
    int n = vertexNum;
    ArcNode *p;
    int j;
    if(v>=n||v<0)
        throw "位置出错";
    cout<<vertex[v]<<" ";
    visited[v] = 1;
    p = adjlist[v].firstarc;
    while(p)
    {
        j = p->adjvex;
        if(visited[j]==0)DFSL(j);
        p = p->next;
    }
}

template<class T>
void ALGraph<T>::DFSL1(int v) {
    
}
template<class T>
void OutDegree(ALGraph<T> g,int od[])
{
    int i;
    int n = g.GetVNum();
    for(i = 0;i<n;i++)
    {
        od[i] = 0;
        ArcNode *p = g.adjlist[i].firstarc;
        while(p){
            od[i]++;
            p = p->next;
        }
    }
}