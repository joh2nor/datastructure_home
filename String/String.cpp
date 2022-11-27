#include "String.h"
#include <iostream>
#include <String.h>
using namespace std;
String::String(){}

String::String(char a[],int n)
{
    length = n;
    for(int i = 0;i<n;i++)
    {
        S[i] = a[i];
    }
    S[n] = '\0';
}

int String::Getlength()
{
    return length;
}

void String::Strcat(String S1)
{
    for(int i = 0;i<S1.length;i++)
    {
        S[i+this->length] = S1.S[i];
    }
    S[this->length+S1.length] = '\0';
    length = this->length+S1.length;
}
void String::Print()
{
    for(int i = 0;i<this->length;i++)
        cout<<this->S[i];
    cout<<endl;
}

char* String::StrSub(int i,int l)
{
    char a[l];
    for(int j = 0;i<l;i++)
        a[j] = a[j+i-1];

    return a;

}

int String::StrIndex_BF(String S1)//暴力算法
{
    int i = 0,j = 0;
    while(j<S1.length&&i<this->length){
        if(S1.S[j]==this->S[i]){i++;j++;}
        else {i = i-j+1;j=0;}
    }
    if(j>=S1.length-1)
        return i - S1.length+1;
    else return 0;
}

bool String::StrCmp(String S2)
{
    return StrCmp(S2);
}

int String::StrIndex_KMP(String S1)
{

}