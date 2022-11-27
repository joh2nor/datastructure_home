#include <iostream>
using namespace std;
const int MaxSize = 100;
struct ArcNode//定义弧表
{
    int adjvex;//邻接点域
    ArcNode *next;//指向下一个弧结点的指针
};

template<class T>
struct VexNode
{
    T vertex;//存放与顶点有关的信息
    ArcNode *firstarc;//指向下一个弧结点的指针
};

template<class T>
class ALGraph{
public:
    ALGraph(){
        vertexNum = 0;
        edgeNum = 0;
        for(int i = 0;i<MaxSize;i++)
            adjlist[i].firstedge = NULL;
    }
    ALGraph(T a[], int n);
    ~ALGraph();//析构函数
    void InsertEdge(int i,int j);//插入一条边，依附的两顶点编号为i和j
    void DFSL(int v);//从v出发深度优先遍历可大顶点递归函数
    void DFSL1(int v);//从v出发深度优先遍历可大顶点非递归函数
    void BFSL(int v);//从v点出发广度优先遍历可大顶点
    friend void OutDegree(ALGraph<T> g,int od[]);//求图中顶点的出度
    int GetVNum(){return vertexNum;}
private:
    T vertex[MaxSize];
    VexNode<T> adjlist[MaxSize];//存放定点表的数组
    int vertexNum,edgeNum;//图的顶点数和边数
};