#include <iostream>
using namespace std;

//队列这个数据结构，从tail插入，从head删除

//使用数组实现队列，假设创建一个capacity=5的队列
//比如依次插入1 2 3 4 5 ，count=5了
//那么head位置在0， tail位置在4
//1出队后，count=4
//head位置在1，tail位置在4，也就是(head+count-1)%capacity
//再次插入6，count=5，这时候tail位置变成了0，也就是(head+count-1)%capacity

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        capacity = k;
        count = 0;
        head = 0;
        data = new int[k];
    }

    ~MyCircularQueue()
    {
    	if (data)
    	{
    		delete[] data;
    	}
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (count == capacity)
        {
        	return false;
        }
        data[(head + count) % capacity] = value;
        count += 1;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (count == 0)
        {
        	return false;
        }
        head += 1;
        count -= 1;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (count == 0)
        {
        	return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
    	if (count == 0)
        {
        	return 0;
        }
        return data[(head+count-1)%capacity];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (count == 0)
        {
        	return true;
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (count == capacity)
        {
        	return true;
        }
        return false;
    }
private:
	int *data;
	int count;
	int capacity;
	int head;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */