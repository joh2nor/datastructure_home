#include "Node.h"
template<class T>
class Cir_LinkList
{
public:
    Cir_LinkList();//无参构造函数
    Cir_LinkList(T a[],int n);//有参构造函数(头插法)
    Cir_LinkList(int n,T a[]);//有参构造函数(尾插法)
    ~Cir_LinkList();//析构函数
    int Length();//获取链表长度
    T Get(int i);//按位查找
    int Locate(T x);//按值查找
    void Insert(int i,T x);//插入
    T Delete(int i);//删除
    void Set(int i,T x);//设置数据域的值
    void PrintList();//遍历链表
    void Union(Cir_LinkList<T>S1);  // 将有序顺序表S1合并到当前有序顺序表中
private:
    Node<T>*first;//头指针

};
