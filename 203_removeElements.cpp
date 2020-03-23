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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *fakeHead = new ListNode(-1);
        ListNode *prev = fakeHead;
        ListNode *cur = head;
        while (cur)
        {
            while (cur && cur->val == val)
            {
                cur = cur->next;
            }
            prev->next = cur;
            prev = cur;
            if (cur)
            {
                cur = cur->next;
            }
        }
        return fakeHead->next;
    }
};
