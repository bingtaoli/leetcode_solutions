#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	ListNode* getMiddle(ListNode* head)
	{
		ListNode *slower = NULL;
		ListNode *slow = head;
		ListNode *fast = head;
		while ( slow && fast && (fast->next) )
		{
			slower = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		//断开链表
		if (slower)
		{
			slower->next = NULL;
		}
		return slow;
	}
    TreeNode* sortedListToBST(ListNode* head) 
    {
    	if (!head)
    	{
    		return NULL;
    	}
    	ListNode *middle = getMiddle(head);
    	cout << middle->val << endl;
    	TreeNode *node = new TreeNode(middle->val);
    	if (head == middle)
    	{
    		return node;
    	}
    	node->left = sortedListToBST(head);
    	node->right = sortedListToBST(middle->next);
    	return node;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	ListNode *a = new ListNode(-10);
	ListNode *b = new ListNode(-3);
	ListNode *c = new ListNode(0);
	ListNode *d = new ListNode(5);
	ListNode *e = new ListNode(9);	
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	Solution s;
	s.sortedListToBST(a);
	return 0;
}