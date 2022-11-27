const int MaxSize = 100;//图中最多顶点个数
template<class T>
class MGraph{
public:
    MGraph(){vertexNum = 0;edgeNum = 0;};//构造函数
    MGraph(T a[],int n);//构造函数，初始化具有n个顶点的零图
    void InsertEdge(int i,int j);//插入顶点为i和j的一条边
    void DFS(int v);//从v出发深度游优先遍历的递归函数
    void BFS(int v);//从v点出发广度优先遍历
private:
    T vertex[MaxSize];//存放图中顶点信息的数组
    int adj[MaxSize][MaxSize];//存放图的邻接矩阵
    int vertexNum,edgeNum;//图的定点数和边数
};