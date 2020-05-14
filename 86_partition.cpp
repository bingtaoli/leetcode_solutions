/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//题解：
//https://leetcode-cn.com/problems/partition-list/solution/fen-ge-lian-biao-by-leetcode/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
    	if (!head)
    	{
    		return NULL;
    	}
    	ListNode *beforeNode = new ListNode(0);
    	ListNode *afterNode = new ListNode(0);
    	//填充两个链表
    	ListNode *p = head;
    	ListNode *p1 = beforeNode;
    	ListNode *p2 = afterNode;
    	while (p)
    	{
    		if (p->val < x)
    		{
    			p1->next = p;
    			p1 = p1->next;
    			p = p->next;
    			//记住断绝和原来链表的关系，你已经在新链表里了！
    			p1->next = NULL;
    		}
    		else 
    		{
    			p2->next = p;
    			p2 = p2->next;
    			p = p->next;
    			//记住断绝和原来链表的关系，你已经在新链表里了！
    			p2->next = NULL;
    		}
    	}
    	//merge 
    	p1->next = afterNode->next;
    	return beforeNode->next;
    }
};

int main(int argc, char const *argv[])
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(4);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(5);
	ListNode *n6 = new ListNode(2);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	Solution s;
	ListNode *p = s.partition(n1, 3);
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}