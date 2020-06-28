/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
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


/*
将链表后半段原地逆转，之后再合并两个半段
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

	ListNode* reverse(ListNode* head)
	{
		ListNode *prev = head;
		ListNode *cur = head->next;
		prev->next = NULL;
		while (cur)
		{
			ListNode *next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}

	void printList(ListNode* head)
	{
		while (head)
		{
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}

    void reorderList(ListNode* head) 
    {
    	if (!head)
    	{
    		return ;
    	}
    	if (!head->next)
    	{
    		return ;
    	}
    	//先从中间截断，这个是标准的截断代码，前半段可能比后半段长一个节点
    	ListNode *middle = head;
    	ListNode *tail = head;
    	while (tail->next && tail->next->next)
    	{
    		middle = middle->next;
    		tail = tail->next->next;
    	}
    	ListNode *p1 = head;
    	ListNode *p2 = reverse(middle->next);
    	middle->next = NULL;
    	//printList(p1);
    	//printList(p2);
    	//merge
    	while ( p1 && p2 )
    	{
    		ListNode *next1 = p1->next;
    		p1->next = p2;
    		p1 = next1;
    		ListNode *next2 = p2->next;
    		p2->next = next1;
    		p2 = next2;
    	}
    }
};

int main(int argc, char const *argv[])
{
	if (1)
	{
		/*
		1->2->3->4
		重新排列为 1->4->2->3.
		*/
		ListNode *node1 = new ListNode(1);
		ListNode *node2 = new ListNode(2);
		ListNode *node3 = new ListNode(3);
		ListNode *node4 = new ListNode(4);
		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		Solution s;
		s.reorderList(node1);
		s.printList(node1);
		cout << endl;
	}
	if (1)
	{
		/*
		[1,2,3,4,5]
		期望结果：
		[1,5,2,4,3]
		*/
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
		s.reorderList(node1);
		s.printList(node1);
		cout << endl;
	}
	if (1)
	{
		/*
		[1,2,3,4,5,6,7]
		期望结果：
		
		*/
		ListNode *node1 = new ListNode(1);
		ListNode *node2 = new ListNode(2);
		ListNode *node3 = new ListNode(3);
		ListNode *node4 = new ListNode(4);
		ListNode *node5 = new ListNode(5);
		ListNode *node6 = new ListNode(6);
		ListNode *node7 = new ListNode(7);
		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = node5;
		node5->next = node6;
		node6->next = node7;
		Solution s;
		s.reorderList(node1);
		s.printList(node1);
		cout << endl;
	}
	return 0;
}
