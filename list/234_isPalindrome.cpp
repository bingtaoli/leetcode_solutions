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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        if (!head || !head->next)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondHead = slow->next;
        slow->next = NULL;
        secondHead = reverseList(secondHead);
        ListNode *p1 = head;
        ListNode *p2 = secondHead;
        while (p1 && p2)
        {
            cout << p1->val << " " << p2->val << endl;
            if (p1->val != p2->val)
            {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if ( (p1&&p1->next) || (p2&&p2->next)  )
        {
            cout << "lenth different" << endl;
            return false;
        }
        return true;
    }
};
