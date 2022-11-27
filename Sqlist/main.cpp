#include <iostream>
#include "seqlist.cpp"
using namespace std;
int main()
{
    int a[]={12,21,3,15,8,16};
    SeqList<int> L1;
    SeqList<int> L2(a,6);
    try            // 有异常抛出throw的函数调用要放在try-catch中
    {  L1.Insert(1,10);
    cout<< "顺序表1的第1个元素是: "<<L1.Get(1)<<endl;
    L2.Insert(8,10);
    cout<< "顺序表2的第4个元素是: "<<L2.Get(4)<<endl;
    }
    catch(const char * msg) {  cout<<msg<<endl;  } //输出捕获到的异常信息
    return  0;
}
