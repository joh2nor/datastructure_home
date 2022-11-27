#include "InThrBiTree.h"
#include <iostream>
using namespace std;
template<class T>
InThrBiTree<T>::InThrBiTree()
{
    this->root = Creat();
    ThrBiTree(root);
}

template<class T>
ThrNode<T>* InThrBiTree<T>::Creat()
{
    ThrNode<T> *root;
    T ch;
    cin>>ch;
    if(ch=='#')
    root = NULL;
    else{
        root = new ThrNode<T>;//生成二叉链表的一个结点
        root->data = ch;
        root->ltag = root->itag = 0;//左右标志都初始化为0
        root->lchild = Creat();//建立左子树
        root->rchild = Creat();//建立右子树
    }
     return root;
}

template<class T>//析构函数
InThrBiTree<T>::~InThrBiTree(void)
{
    Release(root);
}
template<class T>
void InThrBiTree<T>::Release(ThrNode<T>* root)
{
    if(root != NULL)
    {
        Release(root->lchild);//释放左子树
        Release(root->rchild);//释放右子树
        delete root;
    }
}

template<class T>//获取根指针
ThrNode<T>* InThrBiTree<T>::GetRoot()
{
    return root;
}

template<class T>//找中序后继函数
ThrNode<T>* InThrBiTree<T>::Next(ThrNode<T> *p)
{
    ThrNode<T>* q;
    if(p->rtag==1)
        q = p->rchild;//右标志为1，可直接得到后继结点
    else{
        q = p->rchild;//工作指针初始化
        while(q->ltag==0)
        {
            q = q->lchild;//查找最左下结点
        }
    }
    return q;
}
template <class T>//中序线索化二叉链表
void InThrBiTree<T>::ThrBiTree(ThrNode<T> *root)
{
    if(root==NULL) return;
    ThrBiTree(root->lchild);
    if(!root->lchild)
    {
        root->ltag = 1;
        root->lchild = pre;
    }
    if(!root->rchild) root->rtag = 1;//对root的右指针进行处理
    if(pre != NULL)
        if(pre->rtag==1) pre->rchild = root;//设置pre的后继线索
    pre = root;
    ThrBiTree(root->rchild);
}

template<class T>//后序遍历
void InThrBiTree<T>::InOrder(ThrNode<T> *root) {
    ThrNode<T>* p = root;
    if(root == NULL) return;//如果线索链表为空，则空操作返回
    while(p->ltag==0) p = p->lchild;
    cout<<p->data<<" ";
    while(p->rchild!=NULL)//存在后继，依次访问后继结点
    {
        p = Next(p);
        cout<<p->data<<" ";
    }
}
