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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *prev = head;
        ListNode *next = NULL;
        while (prev)
        {
            next = prev->next;
            while (next && next->val == prev->val)
            {
                next = next->next;
            }
            prev->next = next;
            prev = next;
        }
        return head;
    }
};
