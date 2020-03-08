#include <iostream>
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() 
    {  
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        if (!head)
        {
            return -1;
        }
        if (index >= size)
        {
            return -1;
        }
        ListNode *p = head;
        int i(0);
        while (i<index)
        {
            i++;
            p = p->next;
        }
        return p->value; 
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        ListNode *node = new ListNode(val);
        node->next = head;
        head = node;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        ListNode *p = head;
        while (p && p->next)
        {
            p = p->next;
        }
        ListNode *node = new ListNode(val);
        p->next = node;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index > size)
        {
            return;
        }
        ListNode *p = head;
        ListNode *prev = NULL;
        int i(0);
        while (i<index)
        {
            i++;
            prev = p;
            p = p->next;
        }
        ListNode *node = new ListNode(val);
        prev->next = node;
        node->next = p;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if (index >= size)
        {
            return;
        }
        ListNode *p = head;
        ListNode *prev = NULL;
        int i(0);
        while (i<index)
        {
            i++;
            prev = p;
            p = p->next;
        }
        if (prev)
        {
            prev->next = p->next;
        }
        else
        {
            head = p->next;
        }
        size--;
    }
private:
    struct ListNode
    {
        ListNode *next;
        int value;
        ListNode(int v)
        {
            next = NULL;
            value = v;
        };
    };
    ListNode *head;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
