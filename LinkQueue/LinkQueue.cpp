#include "LinkQueue.h"
#include <iostream>
using namespace std;
template<class T>
LinkQueue<T>::LinkQueue()
{
    Node<T> *s;
    s = new Node<T>;
    s->next = NULL;
    front = rear = s;
}
template<class T>
LinkQueue<T>::~LinkQueue()
{
    while(front)
    {
        Node<T> *p;
        p = front->next;
        delete front;
        front = p;
    }
}

template<class T>//将元素x入队
void LinkQueue<T>::EnQueue(T x)
{
    Node<T> *s;
    s = new Node<T>;//生成结点s
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear = s;
}

template<class T>//将队头元素出队
T LinkQueue<T>::DeQueue()
{
    Node<T> *p;
    T x;
    if(front==rear) throw"下溢";
    p = front->next;
    x = p->data;
    front->next = p->next;
    if(p->next==NULL)
    {
        rear = front;
    }
    delete p;
    return x;
}
//队列清空
template<class T>
void LinkQueue<T>::SetNullQueue()
{
    rear = front;
}
//判断链队是否为空
template<class T>
bool LinkQueue<T>::Empty()
{
    if(front==rear) return true;
    else false;
}
//取链队列的对头元素
template<class T>
T LinkQueue<T>::GetQueue()
{
    T x;
    if(front==rear) throw"下溢";
    else
    {
        Node<T> *p = front->next;
        return p->data;
    }

}

