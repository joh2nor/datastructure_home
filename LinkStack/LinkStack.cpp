#include "LinkStack.h"
#include <iostream>
using namespace std;

//构造函数
template<class T>
LinkStack<T>::LinkStack()
{
    top=NULL;
}
//析构函数
template<class T>
LinkStack<T>::~LinkStack()
{
    Node<T> *p;//工作指针
    while(top)//栈顶指针是不为空
    {
        p = top->next;
        delete top;//释放栈顶元素
        top = p;//top指针指向p指针指向的位置
    }
}
//压栈操作
template<class T>
void LinkStack<T>::Push(T x)
{
    Node<T> *s;
    s = new Node<T>;//申请结点
    s->data = x;//给数据域赋值
    s->next = top;//连接
    top = s;//top指针指向栈顶
}
//栈顶元素出栈
template<class T>
T LinkStack<T>::Pop()
{
    Node<T> *p;//工作指针
    T x;
    if(top==NULL) throw"下溢";
    x = top->data;//暂存栈顶元素
    p = top;
    top = top->next;//将栈顶结点摘链
    delete p;
    return x;
}
//取栈顶元素
template<class T>
T LinkStack<T>::GetTop()
{
    if(top!=NULL)
        return top->data;
}
//判栈空操作
template<class T>
bool LinkStack<T>::Empty()
{
    if(top==NULL) return true;
    else return false;
}


