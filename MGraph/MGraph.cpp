#include "MGraph.h"
#include <iostream>
int visited[MaxSize];//为全局标志数组
using namespace std;
template<class T>
MGraph<T>::MGraph(T *a, int n) {//构造函数
    int i,j;
    vertexNum = n;
    edgeNum = 0;
    for(i = 0;i<n;i++)//初始化邻接矩阵
        vertex[i] = a[i];
        for(i = 0;i<n;i++)
            for(j = 0;j<n;j++)
                adj[i][j] = 0;
}

template<class T>//插入顶点i,j依附的边的算法
void MGraph<T>::InsertEdge(int i, int j) {
    if(i<0||i>=vertexNum||j>=vertexNum)
        throw "位置出错";
    adj[i][j] = adj[j][i] = 1;
    edgeNum++;//边数增1
}

template<class T>//深度优先遍历(递归算法)
void MGraph<T>::DFS(int v) {//从v出发深度优先遍历

    int n = vertexNum;
    cout<<vertex[v]<<" ";
    visited[v] = 1;
    for(int j = 0;j<n;j++)
        if(adj[v][j]!=0&&!(visited[j]))
            DFS(j);
}


template<class T>//广度优先遍历
void MGraph<T>::BFS(int v) {//从v出发深度优先遍历
    //int visited[this->vertexNum];//为全局标志数组
    int n  = vertexNum;
    int front,rear;
    if(v>=n||v<0) throw "位置出错";//如果输入不正确抛出异常
    int Q[MaxSize];//Q作为队列
    front = rear = -1;
    cout<<vertex[v]<<" ";//被访问顶点入队
    visited[v] = 1;
    Q[++rear] = v;
    while(front!=rear)
    {
        v = Q[++front];//将队头元素出队
        for(int j = 0;j<n;j++)
            if(adj[v][j]==1&&visited[j]==0)
            {
                cout<<vertex[j]<<" ";
                visited[j] = 1;
                Q[++rear] = j;
            }
    }


}
