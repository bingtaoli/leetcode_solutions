/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

示例 2:
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
    	if (!head)
    	{
    		return NULL;
    	}
    	//旋转一次其实可以理解为：把链表最后一个元素摘掉再插入到最前面去
    	std::vector<ListNode *> stack;
    	ListNode *p = head;
    	while (p)
    	{
    		//vector会拷贝一个指针吗?
    		stack.push_back(p);
    		p = p->next;
    	}
    	//如果旋转200000次，会导致超时
    	//如果队列长度为5，那么旋转5次队列还是原样
    	int i = k % stack.size();
    	while (i)
    	{
    		ListNode *item = stack.back();
    		stack.pop_back();
    		stack.insert(stack.begin(), item);
    		i--;
    	}
    	//构造链表
    	ListNode *node = new ListNode(0);
    	p = node;
    	for (int i = 0; i < stack.size(); i++)
    	{
    		stack[i]->next = NULL;  //reset node next
    		p->next = stack[i];
    		p = p->next;
    	}
    	return node->next;
    }
};

int main()
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	Solution s;
	ListNode *head = s.rotateRight(node1, 2);
	while (head)
	{
		//4->5->1->2->3->NULL
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}