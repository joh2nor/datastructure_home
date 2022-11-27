#include <string.h>
#ifndef STRING_STRING_H
#define STRING_STRING_H
const int MaxSize = 100;
class String {
public:
    String();//无参构造函数
    String(char a[],int n);//有参构造函数
    int Getlength();//获取字符串的长度
    void Strcat(String S1);//子串拼接
    char* StrSub(int i,int l);//求串中从i开始长度为l的子串
    bool StrCmp(String S2);//字符串比较函数
    int StrIndex_BF(String S);//子串定位
    void Insert(String S1,int i);//插入
    void Delete(int i,int l);//删除从i开始长l的子串
    void Replace(String S3);//替代
    void Print();//遍历字符串
    int StrIndex_KMP(String S1);
private:
    char S[MaxSize];
    int length;
};


#endif //STRING_STRING_H
