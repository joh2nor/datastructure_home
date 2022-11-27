#include "Node.h"
template<class T>
class LinkList
{
public:
    LinkList();//无参构造函数
    LinkList(T a[],int n);//有参构造函数(头插法)
    LinkList(int n,T a[]);//有参构造函数(尾插法)
    ~LinkList();//析构函数
    int Length();//获取链表长度
    T Get(int i);//按位查找
    int Locate(T x);//按值查找
    void Insert(int i,T x);//插入
    T Delete(int i);//删除
    void PrintList();//遍历链表
private:
    Node<T>*first;//头指针
};
//按位查找
template<class T>
T LinkList<T>::Get(int i)
{
    Node<T>*p = first;//创建工作指针,指向头结点
    int j = 0;//计数
    while(p&&j<i)//p指针指向的位置不为空并且没有到第i个结点
    {
        p = p->next;//工作指针p指向下一个位置
        j++;//到下一个结点
    }
    if(!p)throw "位置不对";//p指向的位置为空
    else return p->data;//找到了
}

//插入,由于单链表带头结点，表头、表中、表位三种情况的操作语句一致
template<class T>
void LinkList<T>::Insert(int i,T x)
{
    Node<T> *p = first;//创建工作指针
    Node<T> *s;//创建指向新结点的指针
    int j = 0;//计数
    while(p&&j<i-1)//p指向的位置不为空并且没要到第i-1个结点 
    {
        p = p->next;//p指向下一个结点
        j++;//迭代器增加
    }
    if(!p) throw"位置错误";//p指向的位置为空抛出异常
    else
    {
        s = new Node<T>;//创建一个结点,让s指针指向它
        s->data = x;//将需要插入的值存入新快结点的数据域
        s->next = p->next;//将原来第i个节点的地址存入新结点的指针域
        p->next = s;//将新结点的地址存入第i-1个结点的指针域
    }
}

//删除,最后一个结点没有后继结点（需要两个工作指针）
template<class T>
T LinkList<T>::Delete(int i)
{
    Node<T> *p = first;//创建工作指针
    Node<T> *q;//创建工作指针2
    while(p&&j<i-1)//p指向的位置不为空并且没要到第i-1个结点 
    {
        p = p->next;//p指向下一个结点
        j++;//迭代器增加
    }
    if(!p||p->next) throw"位置异常";
    else
    {
        q = p->next;//q指向需要删除的结点
        x = q->data;//将需要删除的结点的数据域的内容存入x
        p->next = q->next;//将第i-1个结点和原来第i+1个结点连接起来
        delete q;//释放第i个结点的空间
        return x;//返回删除结点数据域中的内容
    }
}

//无参数构造函数
template<class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = NULL;//将头结点的指针域设置为空 
}

//有参数构造函数（头插法）
template<class T>
LinkList<T>::LinkList(T a[],int n)
{
    Node<T> *s;//指向待插入结点的指针
    first = new Node<T>;//创建一个头结点
    first->next = NULL;
    for(int i = 0;i<n;i++)
    {
        s = new Node<T>;//s指向待插入结点
        s->data = a[i];
        s->next = first->next;//将新结点与第一个结点连接
        first->next = s;//将插入的结点与头结点相连接
    }
}

//有参数的构造函数（尾插法）
template<class T>
LinkList<T>::LinkList(int n,T a[])
{ 
    first = new Node<T>;//创建头结点
    Node<T> *rear=first,*s;//创建工作指针和指向待插入结点的指针
    for(int i = 0;i<n;i++)
    {
        s = new Node<T>;//创建带插入的结点
        s->data = s[i];//给数据域赋值
        rear->next = s;//连接最后一个结点和新插入的结点
        rear = s;//rear指向最后一个结点
    }
    rear->next = NULL;
}

//析构函数
template<class T>
LinkList<T>::~LinkList()
{
    Node<T> *p = first;//用于移位的工作指针
    Node<T> *q;//用于释放空间的工作指针
    while(p)//p指向的位置不为空
    {
        q = p;//q指向p指向的结点
        p = p->next;//p移动到下一个结点
        delete q;
    }
}
