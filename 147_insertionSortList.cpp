/*
插入排序算法：

1. 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
2. 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
3. 重复直到所有输入数据插入完为止。

示例 1：
输入: 4->2->1->3
输出: 1->2->3->4

示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
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
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
    	ListNode *fakeHead = new ListNode(INT_MIN);
    	fakeHead->next = head;
    	ListNode *prev = head;
    	ListNode *node = head->next;
    	while (node)
    	{
    		if (node->val < prev->val)
    		{
    			//move node
    			ListNode *tmp = fakeHead;
    			while ( tmp->next && tmp->next->val < node->val)
    			{
    				tmp = tmp->next;
    			}
    			ListNode *next = node->next;
    			node->next = tmp->next;
    			tmp->next = node;
    			prev->next = next;  //prev不需要变化，只是node变化了
    			node = next;
    		}
    		else
    		{
    			prev = prev->next; //不需要调整
    			node = node->next;
    		}
    	}
    	return fakeHead->next;
    }
};

int main(int argc, char const *argv[])
{
	{
		/*
		输入: 4->2->1->3
		输出: 1->2->3->4
		*/
		Solution s;
		ListNode *node1 = new ListNode(4);
		ListNode *node2 = new ListNode(2);
		ListNode *node3 = new ListNode(1);
		ListNode *node4 = new ListNode(3);
		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		ListNode *head = s.insertionSortList(node1);
		while (head)
		{
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
	return 0;
}