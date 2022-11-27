
#ifndef SEQSTACK_SEQSTACK_H
#define SEQSTACK_SEQSTACK_H
const int StackSize = 100;
template<class T>
class SeqStack
{
public:
    SeqStack();//构造函数栈的初始化
    ~SeqStack(){};//析构函数
    void push(T x);//将元素x入栈
    T pop();//将栈顶元素弹出
    T GetTop();//取出栈顶元素(并不删除)
    bool Empty();//判断栈是否为空
    int Top(){return top;}//返回呢栈顶值
private:
    T data[StackSize];//存放栈元素的数组
    int top;//栈顶指针，指示栈顶元素在数组中的下标
};


#endif //SEQSTACK_SEQSTACK_H
