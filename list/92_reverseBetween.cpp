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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        //分成三段，第一段0-m，第二段m-n，第三段n-end
        ListNode *start_1 = head;
        ListNode *end_1 = NULL;
        ListNode *start_2 = head;
        ListNode *end_2 = head;
        ListNode *start_3 = NULL;
        ListNode *end_3 = NULL;
        //m=1对应的index=0
        int i(m-1), j(n-1);
        while (i > 0)
        {
            ListNode *tmp = start_2;
            start_2 = start_2->next;
            end_1 = tmp;
            i--;
        }
        while (j > 0)
        {
            end_2 = end_2->next;
            j--;
        }
        start_3 = end_2->next;
        //reverse second section
        ListNode *prev;
        ListNode *current = start_2;
        ListNode *next = start_2->next;
        while (current != end_2)
        {
            prev = current;
            current = next;
            if (next)
            {
                next = next->next;
            }
            current->next = prev;
        }
        //combine three
        //combine 1 & 2
        ListNode *new_list_head = NULL;
        if (end_1)
        {
            new_list_head = start_1;
            end_1->next = end_2;
        }
        else
        {
            new_list_head = end_2;
        }
        //combine 2 &3
        start_2->next = start_3;
        return new_list_head;
    }
};
