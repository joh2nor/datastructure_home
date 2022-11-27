#include "seqstack.h"
#include <iostream>
using namespace std;
template<class T>
//构造函数栈的初始化
SeqStack<T>::SeqStack()
{
    top = -1;//栈顶指针初始位置
}
//将元素x入栈
template<class T>
void SeqStack<T>::push(T x)
{
    if(top==StackSize-1) throw"栈上溢";
    data[++top] = x;
}
//将栈顶元素弹出
template<class T>
T SeqStack<T>::pop()
{
    if(top==-1) throw"栈下溢";
    return data[top--];
}
//取出栈顶元素(并不删除)
template<class T>
T SeqStack<T>::GetTop()
{
    if(top==-1) throw"栈下溢";
    else return data[top];
}
//判断栈是否为空
template<class T>
bool SeqStack<T>::Empty()
{
    if(top==-1) return true;
    else return false;
}

