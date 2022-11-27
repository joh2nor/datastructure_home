#include <iostream>
#include "InThrBiTree.cpp"
ThrNode<char>* pre;
int main() {
    InThrBiTree<char> inbt;
    ThrNode<char> *p = inbt.GetRoot();
    cout<<"----中序遍历二叉树----"<<endl;
    inbt.InOrder(p);
    return 0;
}
