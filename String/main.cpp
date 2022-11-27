#include <iostream>
#include "String.cpp"
using namespace std;
int GetNext(int j,char T[])
{
    if(j==0) return -1;
    if(j>0)
    {
        int k = GetNext(j-1,T);
        while(k>0)
        {
            if(T[j-1]==T[k])
            {
                return k+1;
            }
            else k = GetNext(k,T);
            return 0;
        }
    }
    return 0;
}
void GetNext(char T[],int m)
{
    int j = 0,k = -1;
    int next[m];
    next[j]  = k;
    while(T[j]!='\0')
        if(k==-1||T[j]==T[k])
        {
            j = j +1;
            k = k+1;
            next[j] = k;
            else k = next[k];
        }
}
int main() {
//    char c[10] = {'h','e','l','l','o','w','o','r','l','d'};
//    char s[5] = {'w','o','r','l','d'};
//    String S1(c,10);
//    String S2(s,5);
//    S1.Print();
//    S2.Print();
//    cout<<S1.StrIndex_BF(S2);
    char *s = "1001001100011001";
    cout<<GetNext(16,s);
    return 0;



}
