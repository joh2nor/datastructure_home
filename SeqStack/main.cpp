#include <iostream>
#include "seqstack.cpp"
using namespace std;
void Conversion(int N,int r)
{
    SeqStack<int> S;//声明一个顺序栈对象
    while(N)
    {
        if(r==16)
        {
            char s;
            s = N%r;
            if(s<=9)
            {

                N=N/r;
                s = s + '\0';
                S.push(s);
            }
            else if(s>=10)
            {
                s = N%r;
                N=N/r;
                s = s + 'A';
                S.push(s);
            }
            while(!S.Empty())
            {
                int e = S.pop();
                cout<<e;
            }
        }
        else
        {
            S.push(N%r);
            N=N/r;
            while(!S.Empty())
            {
                int e = S.pop();
                cout<<e;
            }
        }

    }
}
int main() {
//    try
//    {
//        Conversion(80,16);
//    }
//    catch (const char *msg) {cout<<msg<<endl;}

    return 0;
}
