#include "cir_linklist.h"
#include <iostream>
using namespace std;
//无参构造函数
template<class T>
Cir_LinkList<T>::Cir_LinkList()
{
    first = new Node<T>;
    first->next = NULL;//(在iostream中定义)
}
//有参构造函数(头插法)
template<class T>
Cir_LinkList<T>::Cir_LinkList(T a[],int n)
{
    first = new Node<T>;//创建头结点
    Node<T> *s;
    first->next = NULL;
    for(int i = 0;i<n;i++)
    {
        s = new Node<T>;
        s->data = a[i];
        s->next = first->next;
        first->next = s;
    }

}
//有参构造函数(尾插法)
template<class T>
Cir_LinkList<T>::Cir_LinkList(int n,T a[])
{
    first = new Node<T>;
    first->next = NULL;
    Node<T> *s,*r = first;
    for(int i = 0;i<n;i++)//r是尾指针
    {
        s = new Node<T>;
        s->data = a[i];
        r->next = s;
        r = s;
        r->next = NULL;
    }
}
//析构函数
template<class T>
Cir_LinkList<T>::~Cir_LinkList()
{

    Node<T> *p = first;
    while(p!= first)
    {
        Node<T> *q = p->next;
        p = p->next;
        delete q;
    }
    delete first;
}
//获取链表长度
template<class T>
int Cir_LinkList<T>::Length()
{
    Node<T> *p = first;//用于移位的工作指针
    int j = 0;
    while(p!=first)
    {
        p = p->next;//p移动到下一个结点
        j++;
    }
    return j;
}
//按位查找
template<class T>
T Cir_LinkList<T>::Get(int i)
{
    Node<T>*p = first;//创建工作指针,指向头结点
    int j = 0;//计数
    while(p!=first&&j<i)//p指针指向的位置不为空并且没有到第i个结点
    {
        p = p->next;//工作指针p指向下一个位置
        j++;//到下一个结点
    }
    if(p = first)throw "位置不对";//p指向的位置为空
    else return p->data;//找到了
}
//按值查找
template<class T>
int Cir_LinkList<T>::Locate(T x)
{
    Node<T> *p = first;//用于移位的工作指针
    int j = 0;//计数
    while(p!=first)
    {
        p = p->next;//p移动到下一个结点
        j++;
        if(x==p->data)
            return j;
    }
}
//插入
//template<class T>
//void Insert(int i,T x)
//{
//    Node<T> *p = first;//创建工作指针
//    Node<T> *s;//创建指向新结点的指针
//    int j = 0;//计数
//    while(p&&j<i-1)//p指向的位置不为空并且没要到第i-1个结点
//    {
//        p = p->next;//p指向下一个结点
//        j++;//迭代器增加
//    }
//    if(!p) throw"位置错误";//p指向的位置为空抛出异常
//    else
//    {
//        s = new Node<T>;//创建一个结点,让s指针指向它
//        s->data = x;//将需要插入的值存入新快结点的数据域
//        s->next = p->next;//将原来第i个节点的地址存入新结点的指针域
//        p->next = s;//将新结点的地址存入第i-1个结点的指针域
//    }
//}
//遍历链表
template<class T>
void Cir_LinkList<T>::PrintList()
{
    Node<T> *p = first;//用于移位的工作指针
    while(p) {
        p = p->next;//p移动到下一个结点
        if(p)
            cout << p->data << " ";//输出p当前指向的结点的数据域的值
    }
    cout<<endl;
}



