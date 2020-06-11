/*
25. K 个一组翻转链表

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse(ListNode* head, int k)
	{
		//printf("enter reverse head:%d \n", head->val);
		ListNode *cur = head;
		ListNode *next = head->next;
		int i = 0;
		//调整k-1次
		while ( next && i < k-1 )
		{
			ListNode *p = next;
			next = next->next;
			p->next = cur;
			cur = p;
			i++;
		}
		//printf("left reverse cur:%d \n", cur->val);
		return cur;
	}

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
		int len(0);
		ListNode *p = head;
		while ( p )
		{
			p = p->next;
			len++;
		}
		int section = len / k;
		if (section == 0)
		{
			return head;
		}
		//printf("len:%d k:%d section:%d\n", len, k, section);
		int round(0);
		ListNode *newListHead = head;
		//一段一段翻转
    	while ( round < section )
    	{
    		//slow and fast
    		ListNode *slow = newListHead;
    		ListNode *fast = newListHead;
    		ListNode *prev = NULL; //这段之前的节点
    		ListNode *next = NULL; //这段之后的节点
    		for (int i = 0; i < round * k; i++)
    		{
    			prev = slow;
    			slow = slow->next;
    		}
    		for (int i = 0; i < round * k + k - 1; i++)
    		{
    			fast = fast->next;
    		}
    		next = fast->next;
    		//翻转
    		ListNode *new_section_head = reverse(slow, k);
    		if (round == 0)
    		{
    			//第一段，修改newListHead
    			//printf("new list head:%d\n", new_section_head->val);
    			newListHead = new_section_head;
    		}
    		if (prev)
    		{
    			prev->next = new_section_head;
    		}
    		slow->next = next;
    		round++;
    	}
    	return newListHead;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	{
		//1->2->3->4->5
		ListNode *node1 = new ListNode(1);
		ListNode *node2 = new ListNode(2);
		ListNode *node3 = new ListNode(3);
		ListNode *node4 = new ListNode(4);
		ListNode *node5 = new ListNode(5);
		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = node5;
		ListNode *head = s.reverseKGroup(node1, 2);
		while (head)
		{
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
	{
		//1->2->3->4->5
		//k=3
		//3->2->1->4->5
		ListNode *node1 = new ListNode(1);
		ListNode *node2 = new ListNode(2);
		ListNode *node3 = new ListNode(3);
		ListNode *node4 = new ListNode(4);
		ListNode *node5 = new ListNode(5);
		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = node5;
		ListNode *head = s.reverseKGroup(node1, 3);
		while (head)
		{
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
	return 0;
}