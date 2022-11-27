#include <iostream>
#include "LinkStack.cpp"
using namespace std;
int main() {
    LinkStack<int> LS;
    try
    {
        for(int i = 0;i<5;i++)
        {
            LS.Push(i);
        }
        cout<<"栈顶的元素为:"<<LS.GetTop()<<endl;
        LS.Pop();//出栈
        cout<<"出栈后栈顶的元素为:"<<LS.GetTop()<<endl;
        if(LS.Empty())cout<<"栈空了"<<endl;
        else cout<<"栈没空"<<endl;
    }
    catch (const char *msg) {cout<<msg<<endl;}


    return 0;
}
