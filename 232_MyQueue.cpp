#include <iostream>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        stack1.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        if (stack2.empty())
        {
            //move stack1 to stack2
            for (int i = stack1.size()-1; i >=0; i--)
            {
                stack2.push_back(stack1[i]);
            }
            stack1.clear();
        }
        int value = stack2.back();
        stack2.pop_back();
        return value;
    }
    
    /** Get the front element. */
    int peek() 
    {
        if (stack2.empty())
        {
            //move stack1 to stack2
            for (int i = stack1.size()-1; i >=0; i--)
            {
                stack2.push_back(stack1[i]);
            }
            stack1.clear();
        }
        int value = stack2.back();
        return value;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return stack1.size() + stack2.size() == 0;
    }
private:
    vector<int> stack1;
    vector<int> stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
