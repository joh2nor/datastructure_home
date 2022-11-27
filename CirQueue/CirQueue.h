//
// Created by 蒲贺良 on 2022/10/16.
//

#ifndef CIRQUEUE_CIRQUEUE_H
#define CIRQUEUE_CIRQUEUE_H
const int QueueSize = 100;
template<class T>
class CirQueue {
public:
    CirQueue();//构造函数
    ~CirQueue(){};//析构函数
    void EnQueue(T x);//将元素x入队
    T DeQueue();//将队头元素出队
    T GetQueue();//取队头元素(不删除)
    bool Empty();//判断队列是否为空
    int GetFrront(){return front;};//取队头值
    int GetRear(){return rear;}//取队尾值
private:
    T data[QueueSize];//存放队列元素的数组
    int front,rear;//分别指向队头元素的钱一个位置和队尾位置
};


#endif //CIRQUEUE_CIRQUEUE_H
