template<class T>
struct BiNode//结点类型
{
    T data;
    BiNode<T> *lchild,*rchild;
};

template<class T>
class BiTree
{
public:
    BiTree();//无参数构造函数
    //BiTree(BiNode<T> *&root);//有参数构造函数
    ~BiTree();//析构函数
    void PreOrder(){PreOrder(root);}//先序遍历二叉树
    void InOrder(){InOrder(root);}//中序遍历二叉树
    void PostOrder(){PostOrder(root);}//后序遍历二叉树
    void LevelOrder(){LevelOrder(root);}//层序遍历二叉树
    BiNode<T> *GetRoot(){return this->root;}
private:
    BiNode<T> *root;
    BiNode<T> *Creat();
    void Release(BiNode<T> *root);
    void PreOrder(BiNode<T> *root);//先序遍历二叉树
    void InOrder(BiNode<T> *root);//中序遍历二叉树
    void PostOrder(BiNode<T> *root);//后序遍历二叉树
    void LevelOrder(BiNode<T> *root);//层序遍历二叉树
};

