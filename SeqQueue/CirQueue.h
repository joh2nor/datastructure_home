const int QueueSize = 100;//定义存储队列元素的数组的最大长度
template<class T>//定义模版类CirQueue
class CirQueue
{
public:
    CirQueue();//构造函数置空队
    ~CirQueue(){};//析构函数
    void EnQueue(T x);//将元素x入队
    T DeQueue();//循环队头元素出队
    T GetQueue();//取出队头元素
    bool Empty();//判断队列是否为空
    int GetFrront(){return front;}//取出队头值
    int GetRear(){return rear;}//取队尾值
private:
    T data[QueueSize];//存放队列元素的数组
    int front,rear;//分别指向队头元素的钱一个元素和队尾元素位置
};