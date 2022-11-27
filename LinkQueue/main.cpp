#include <iostream>
#include "LinkQueue.cpp"
using namespace  std;
int main() {
    try {
        LinkQueue<int> LQ;
        for (int i = 10; i < 100; i = i + 10)
            LQ.EnQueue(i);
        cout << "队头元素为：" << LQ.GetQueue() << endl;
        LQ.DeQueue();
        cout<<"原队头元素出列后新队头元素:"<<LQ.GetQueue()<<endl;
        LQ.SetNullQueue();//置空
        if(LQ.Empty())cout<<"LQ空了";
        else cout<<"LQ没空"<<endl;
    }

    catch(const char *msg) {cout<<msg<<endl;}
    return 0;
}
