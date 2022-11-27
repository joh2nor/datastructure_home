#include <iostream>
#include "cir_linklist.cpp"
using namespace std;
int main() {
    int a[6]={0,1,2,3,4,5};
    Cir_LinkList<int> CL1(6,a);
    Cir_LinkList<int> CL2(a,6);
    try
    {
        CL2.PrintList();
        CL1.PrintList();
    }
    catch(const char *msg){cout<<msg<<endl;}
        

        
    return 0;
}
