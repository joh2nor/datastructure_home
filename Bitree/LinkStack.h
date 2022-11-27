#include "Node.h"
template<class T>
class LinkStack{
public:
    LinkStack();//构造函数
    ~LinkStack();//析构函数
    void Push(T x);//元素x入栈
    T Pop();//栈顶元素出栈
    T GetTop();//取栈顶元素
    bool Empty();//判断链栈是否为空栈
private:
    Node<T> *top;//栈顶指针，即链栈的头指针
};

