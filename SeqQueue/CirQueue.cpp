#include "CirQueue.h"
//构造函数置空队
template<class T>
CirQueue<T>::CirQueue()
{
    front = rear = 0;
}
//将元素x入队
template<class T>
void CirQueue<T>::EnQueue(T x)
{
    if((rear+1)%QueueSize==front) throw"上溢";
    rear = (rear+1)%QueueSize;//队尾指针在循环意义上+1
    data[rear] = x;
}
//将队头元素出队
template<class T>
T CirQueue<T>::DeQueue()
{
    if(rear == front) throw"下溢";
    front = (front+1)%QueueSize;//在队头循环意义上+1
    return data[front];
}
//取出队头元素
template<class T>
T CirQueue<T>::GetQueue()
{
    int i;
    if(rear==front)throw"下溢";
    i = (front+1)%QueueSize;//注意不要给头指针赋值
    return data[i];
}
//判断队列是否为空
template<class T>
bool CirQueue<T>::Empty()
{
    if(front==rear) return true;
    else return false;
}




