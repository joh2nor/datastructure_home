#include "seqlist.h"
#include <iostream>
using namespace std;
template <class T>
//无参构造函数
SeqList<T>::SeqList()
{
    length = 0;
}

//有参构造函数
template<class T>
SeqList<T>::SeqList(T a[],int n)
{
    if(n>MaxSize) throw "参数非法";
    for (int i = 0;i<n;i++)
        data[i] = a[i];
    length = n;
}

//插入
template<class T>
void SeqList<T>::Insert(int i,T x)
{
    if(length>=MaxSize)throw"上溢出";
    if(i<1||i>length+1)throw"位置不对";//length+1因为这是顺序表
    for(int j = length;j>=i;j--)
        data[j] = data[j-1];
        
    data[i-1] = x;
    length++;
}

//删除
template<class T>
T SeqList<T>::Delete(int i)
{
    if(length==0) throw "位置错误!";
    T x = data[i-1];//先把要删除的元素存进x
    for(int j=i;j<length;j++)//后面的元素向前覆盖一个位置
    {
        data[i-1]=data[i];
    }
    length--;
    return 0;
}

//按位查找
template<class T>
T SeqList<T>::Get(int i)
{
    if(i<0||i>length) throw "位置错误";
    return data[i-1];//返回查找到的元素
}

//按值查找
template <class T>
int SeqList<T>::Locate(T x)
{
    for(int i = 0;i<length;i++)
        if(data[i]==x)return i+1;//返回逻辑序号
    return 0;
}
//顺序表的遍历
template<class T>
void SeqList<T>::PrintList()
{
    for(int i = 0;i<length;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
//将有序顺序表S1合并到当前有序顺序表中
template<class T>
void SeqList<T>::Union(SeqList<T> S1)
{

}



