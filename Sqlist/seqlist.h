const int MaxSize = 100;
template <class T>
class SeqList
{
public:
    SeqList();//构造函数
    SeqList(T a[],int n);//带参构造函数
    int GetLength();//获取顺序表的长度
    T Get(int i);//获取顺序表的值
    int Locate(T x);//定位x在顺序表中的位置
    void Insert(int i,T x);//将x插入顺序表中的i位置
    T Delete(int i);//删除第i个位置的元素
    void PrintList();         // 顺序表的遍历（输出）
    void Union(SeqList<T> S1);  // 将有序顺序表S1合并到当前有序顺序表中
private:
    T data[MaxSize];//顺序表
    int length;//顺序表的长度
};