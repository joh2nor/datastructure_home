#include <iostream>
#include "BiTree.cpp"
#include "LinkStack.cpp"
using namespace std;
template<class T>//计算叶子结点数
void CountLeaf(BiNode<T> *root,int &count)
{
    if(root!=NULL)
    {
        if(root->lchild == NULL&&root->rchild == NULL)
            count++;//若root所指的结点是叶结点，则计数器加1
        CountLeaf(root->lchild,count);//累计左子树上的叶结点数
        CountLeaf(root->rchild,count);//累计右子树上的叶结点数
    }
}
template<class T>//计算二叉树的高度
int Height(BiNode<T> *root)
{
    int L,R;
    if(root == NULL) return 0;
    else{
        L = Height(root->lchild);
        R = Height(root->rchild);
        return (L>R)?L+1:R+1;
    }
}
template<class T>
int NoDiGui_CountLeaf(BiNode<T> *root,int &count)
{
    if(root == NULL)
        return 0;
    LinkStack <BiNode<T>*> st;
    while (root != NULL || !st.Empty())
    {
        while (root != NULL)
        {
            st.Push(root);
            root = root->lchild;
        }

        if (!st.Empty())
        {
            root = st.GetTop();
            st.Pop();
            if(root->lchild == NULL && root->rchild == NULL)
                count++;
            root = root -> rchild;
        }
    }

    return count;
}
int main() {
    int count = 0;
    cout<<"输入拓展二叉树的结点先序序列："<<endl;
    BiTree<char> bt;//创建一棵树
    BiNode<char> *r = bt.GetRoot();//获取指向根结点的指针
    cout<<"------先序遍历------"<<endl;
    bt.PreOrder();cout<<endl;
    cout<<"------中序遍历------"<<endl;
    bt.InOrder();cout<<endl;
    cout<<"------后序遍历------"<<endl;
    bt.PostOrder();cout<<endl;
    cout<<"------层序遍历------"<<endl;
    bt.LevelOrder();
    cout<<endl;
    CountLeaf(r,count);
    cout<<"叶结点数(递归算法)="<<count<<endl;
    count = 0;
    NoDiGui_CountLeaf(r,count);
    cout<<"叶结点数(非递归算法)="<<count<<endl;
    cout<<"高度="<<Height(r)<<endl;
    return 0;
}
