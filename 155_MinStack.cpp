#include <iostream>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) 
    {
        Store item;
        item.value = x;
        item.min = x;
        if (stack.size() != 0)
        {
            int curMin = stack.back().min;
            if (x > curMin)
            {
                item.min = curMin;
            }
        }
        stack.push_back(item);
    }
    
    void pop() 
    {
        if (!stack.size())
        {
            return;
        }
        stack.pop_back();
        return;
    }
    
    int top() 
    {
        if (!stack.size())
        {
            return INT_MAX;
        }
        return stack.back().value;
    }
    
    int getMin() 
    {
        if (!stack.size())
        {
            return INT_MAX;
        }
        return stack.back().min;
    }
private:
    struct Store
    {
        int value;
        int min;
    };
    vector<Store> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
