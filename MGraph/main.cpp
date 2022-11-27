#include <iostream>
#include <string.h>
#include "MGraph.cpp"
int main() {
    string a[]={"v0","v1","v2","v3","v4","v5","v6","v7","v8"};
    MGraph<string> MG(a,9);
    int bian;
    cout<<"请输入边数:"<<endl;
    cin>>bian;
    int b,c;
    for(int i = 0;i<bian;i++)
    {
        cout<<"请输入第"<<i+1<<"条边的两个顶点"<<endl;
        cin>>b>>c;
        MG.InsertEdge(b,c);
    }
//    MG.InsertEdge(0,1);
//    MG.InsertEdge(0,2);
//    MG.InsertEdge(1,3);
//    MG.InsertEdge(1,4);
//    MG.InsertEdge(2,5);
//    MG.InsertEdge(2,6);
//    MG.InsertEdge(3,7);
//    MG.InsertEdge(4,7);
//    MG.InsertEdge(7,8);
//    MG.InsertEdge(5,6);
    cout<<"请输入遍历的起点:"<<endl;
    int v;
    cin>>v;
    cout<<"图的深度优先遍历:"<<endl;
    MG.DFS(v);
    cout<<endl;
    for(int i = 0;i<MaxSize;i++)
        visited[i] = 0;
    cout<<"图的广度优先遍历:"<<endl;
    MG.BFS(v);
    return 0;
}
