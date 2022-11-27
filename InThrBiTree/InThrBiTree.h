typedef bool flag;
template <class T>
struct ThrNode//二叉线索树的结点结构
{
    T data;
    ThrNode<T> *lchild,*rchild;
    flag ltag,rtag;
};

template<class T>
class InThrBiTree
{
public:
    InThrBiTree();//构造函数,建立中序线索链表
    ~InThrBiTree();//析构函数，释放线索链表中各结点的存储空间
    ThrNode<T>* GetRoot();//获取根结点
    ThrNode<T>* Next(ThrNode<T>* p);//查找结点p的后继
    void InOrder(ThrNode<T>* root);//中序遍历线索链表
private:
    ThrNode<T> *root;//指向线索链表的头指针
    ThrNode<T> *Creat();//构造函数调用
    void ThrBiTree(ThrNode<T> *root);//构造函数调用
    void Release(ThrNode<T> *root);//析构函数调用
};

