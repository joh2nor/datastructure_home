#include "BiTree.h"
#include "CirQueue.cpp"
#include <iostream>
using namespace std;
template<class T>//先序遍历二叉树
void BiTree<T>::PreOrder(BiNode<T> *root)
{
    if(root == NULL) return;
    else{
        cout<<root->data<<endl;//访问根结点
        PreOrder(root->lchild);//先序遍历左子树
        PreOrder(root->rchild);//先序遍历右子树
    }
}

template<class T>//中序遍历二叉树
void BiTree<T>::InOrder(BiNode<T> *root)
{
    if(root == NULL) return;
    else{
        InOrder(root->lchild);//中序遍历左子树
        cout<<root->data<<endl;//访问根结点
        InOrder(root->rchild);//中序遍历右子树
    }
}

template<class T>//后序遍历二叉树
void BiTree<T>::PostOrder(BiNode<T> *root)
{
    if(root == NULL) return;
    else{
        
        PostOrder(root->lchild);//后序遍历左子树
        PostOrder(root->rchild);//后序遍历右子树
        cout<<root->data<<endl;//访问根结点
    }
}

template<class T>//层序遍历二叉树
void BiTree<T>::LevelOrder(BiNode<T> *root)
{
    typedef BiNode<T>* Pointer;//Pointer为类型名
    CirQueue<Pointer> Q;//创建循环队列
    if(root == NULL) return;
    Q.EnQueue(root);//根指针入队
    while(!Q.Empty())
    {
        BiNode<T> *p = Q.DeQueue();//出队列
        cout<<p->data<<" ";//访问结点的信息
        if(p->lchild != NULL) Q.EnQueue(p->lchild);//非空左指针入队
        if(p->rchild != NULL) Q.EnQueue(p->rchild);//非空右指针入队
    }
}

template<class T>
BiTree<T>::BiTree()
{
    cout<<"请输入创建一颗二叉树的结点数据:"<<endl;
    this->root = Creat();
}

template<class T>
BiNode<T>* BiTree<T>::Creat()
{
    BiNode<T> *root;
    char ch;
    cin>>ch;
    if(ch=='#'){
        root=NULL;
    }
    else{
        root = new BiNode<T>;
        root->data = ch;
        root->lchild = Creat();
        root->rchild = Creat();
    }
    return root;
}
template<class T>//析构函数
BiTree<T>::~BiTree()
{
    Release(root);//释放结点
}
template<class T>
 void BiTree<T>::Release(BiNode<T> *root)
 {
     if(root != NULL)
     {
         Release(root->lchild);//释放左子树
         Release(root->rchild);//释放右子树
         delete root;//释放当前根结点
     }
 }

