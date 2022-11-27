#include <iostream>
#include "CirQueue.cpp"
using namespace std;
int main() {
    try{
        CirQueue<int> CQ;
        for(int i = 0;i<10;i=i+2)
            CQ.EnQueue(i);
        cout<<"队头元素"<<CQ.GetQueue()<<endl;
        CQ.DeQueue();
        cout<<"队头元素"<<CQ.GetQueue()<<endl;
        if(CQ.Empty())cout<<"队列为空"<<endl;
        else cout<<"队列不为空"<<endl;
    }
    catch (const char *msg) {cout<<msg<<endl;}
    return 0;
}
