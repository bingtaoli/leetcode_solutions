#include <iostream>
using namespace std;

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode head(0);
        ListNode *p = &head;
        while (p1 || p2)
        {
            if (p1 && p2)
            {
                if (p1->val < p2->val)
                {
                    p->next = p1;
                    p1 = p1->next;
                    p = p->next;
                }
                else if (p1->val == p2->val)
                {
                    //merge p1
                    p->next = p1;
                    p1 = p1->next;
                    p = p->next;
                    //merge p2
                    p->next = p2;
                    p2 = p2->next;
                    p = p->next;
                }
                else
                {
                    p->next = p2;
                    p2 = p2->next;
                    p = p->next;
                }
            }
            else if (p1)
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
        }
        return head.next;
    }
};
