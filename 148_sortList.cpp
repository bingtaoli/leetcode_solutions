/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    链表排序，二分
    1、中间拆开
    2、排序合并
    3、递归
    */
    ListNode* sortList(ListNode* head) 
    {
        if (!head)
        {
            return NULL;
        }
        if (!head->next)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *tmp = slow->next;
        slow->next = NULL;
        cout << "split complete" << endl;
        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);
        //merge 
        ListNode fakeHead(0);
        ListNode *p = &fakeHead;
        while (left && right)
        {
            if (left->val < right->val)
            {
                p->next = left;
                left = left->next;
            }
            else
            {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        cout << "merge complete" << endl;
        if (left)
        {
            p->next = left;
        }
        else if (right)
        {
            p->next = right;
        }
        return fakeHead.next;
    }
};
