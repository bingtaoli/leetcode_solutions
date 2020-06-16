/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
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
	ListNode *merge(ListNode *l1, ListNode *l2)
	{
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		while (l1 || l2)
		{
			if (!l1)
			{
				p->next = l2;
				l2 = l2->next;
			}
			else if (!l2)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		return head->next;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
    	if (lists.size() == 0)
    	{
    		return NULL;
    	}
    	ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
        	head = merge(head, lists[i]);
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
	/*
	[
	  1->4->5,
	  1->3->4,
	  2->6
	]
	输出: 1->1->2->3->4->4->5->6
	*/
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(4);
	ListNode *node3 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	ListNode *node4 = new ListNode(1);
	ListNode *node5 = new ListNode(3);
	ListNode *node6 = new ListNode(4);
	node4->next = node5;
	node5->next = node6;
	ListNode *node7 = new ListNode(2);
	ListNode *node8 = new ListNode(6);
	node7->next = node8;
	//merge
	vector<ListNode*> lists;
	lists.push_back(node1);
	lists.push_back(node4);
	lists.push_back(node7);
	Solution s;
	ListNode *head = s.mergeKLists(lists);
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}