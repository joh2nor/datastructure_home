#include <iostream>
using namespace std;
const int MAX  = 9999;//最大常量
const int L=20;
struct element
{
    int weight;//权重
    int lchild,rchild,parent;
};//结点结构类型说明
typedef struct{
    char bits[MAX];//用于存放串
    int start;//用于存放编码在位串中的起始位置
    char ch;//存储字符，一个字符对应一个结构
}codetype;
void Select(element hT[],int &i1,int &i2,int k)
{
    int min1 = MAX,min2 = MAX;//MAX为较大常数
    i1 = 0;i2 = 0;//分别记录最小和次小所在的下标值
    for(int i = 0;i<k;i++)
    {
        if(hT[i].parent==-1)//在双亲为空的结点中寻找
        {
            if(hT[i].weight<min1)
            {
                min2 = min1;
                i2  = i1;
                min1 = hT[i].weight;
                i1 = i;
            }
            else if (hT[i].weight<min2)
            {
                min2 = hT[i].weight;
                i2 = i;
            }
        }

    }
}
void HuffmanTree(element hT[],int w[],int n)//建立哈夫曼树
{
    int i,k,i1,i2;
    for(int i = 0;i<2*n-1;i++)
        hT[i].parent = hT[i].lchild = hT[i].rchild = -1;//设置初始值
    for(i = 0;i<n;i++)
        hT[i].weight = w[i];//把权值赋值到前n个数组中
    for(k = n;k<2*n-1;k++)
    {
        Select(hT,i1,i2,k);
        hT[i1].parent = hT[i2].parent = k;
        hT[k].weight = hT[i1].weight+hT[i2].weight;
        hT[k].lchild = i1;
        hT[k].rchild = i2;
    }
}
void HuffmanCode(element hT[],codetype code[],int n)//哈夫曼编码
{
    int i,c,p;
    codetype cd;
    for(i = 0;i<n;i++)
    {
        cd.start = n;//最后一个字符
        c = i;
        p = hT[c].parent;
        while(p!=-1)
        {
         cd.start--;
         if(hT[p].lchild == c)
             cd.bits[cd.start] = '0';//i是p的做孩子，分支上置'0'
         else
             cd.bits[cd.start] = '1';//i是p的右孩子，分支上置'1'
         c = p;
         p = hT[c].parent;
        }
        code[i] = cd;//注意cd.ch是空的
    }
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
