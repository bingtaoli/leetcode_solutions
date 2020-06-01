/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
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
	/*
	ListNode *reverse(ListNode *head)
	{
		//翻转链表
		ListNode *cur = head;
		ListNode *next = head->next;
		while ( next )
		{
			ListNode *p = next;
			next = next->next;
			p->next = cur;
			cur = next;
		}
		return cur;
	}
	*/
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
    	if (!head)
    	{
    		return NULL;
    	}
    	//思路：链表可能拆成三段，也可能只有一段
    	ListNode *left = head;
    	ListNode *right = head;
    	ListNode *section_1_end = NULL;
    	ListNode *section_3_start = NULL;
    	ListNode *p = NULL;
    	int i = 1;
    	while (i < m)
    	{
    		section_1_end = left;
    		left = left->next;
    		i++;
    	}
    	i = 1;
    	while (i < n)
    	{
    		right = right->next;
    		i++;
    	}
    	section_3_start = right->next;
    	//翻转中间一段
    	ListNode *cur = left;
		ListNode *next = left->next;
		left->next = NULL;
		i = 1;
		int j = n - m; //改变的箭头数目
		while ( next && i <= j )
		{
			ListNode *p = next;
			next = next->next;
			p->next = cur;
			cur = p;
			i++;
		}
		//printf("cur:%d left:%d\n", cur->val, left->val);
		//cur is head of section_2, left is end of section_2
		ListNode *new_head = head;
		if (section_1_end)
		{
			section_1_end->next = cur;
		}
		else
		{
			new_head = cur;
		}
		//combine the third part
		left->next = section_3_start;
		return new_head;
    }
};

int main(int argc, char const *argv[])
{
	//输入: 1->2->3->4->5->NULL, m = 2, n = 4
	//输出: 1->4->3->2->5->NULL
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
	ListNode *h = NULL;
	//test 1
	h = s.reverseBetween(node1, 2, 4);
	while (h)
	{
		cout << h->val << " ";
		h = h->next;
	}
	cout << endl;
	//test2
	h = s.reverseBetween(node1, 1, 3);
	while (h)
	{
		cout << h->val << " ";
		h = h->next;
	}
	cout << endl;
	return 0;
}