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
    ListNode* reverseList(ListNode* l1)
    {
        //反转链表，本题根本不需要，我只是单纯看到链表想写个反转练练手..
        if (!l1)
        {
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* current = NULL;
        ListNode* next = NULL;
        current = l1;
        next = l1->next;
        while (next)
        {
            current->next = prev;
            current = next;
            prev = current;
            next = next->next;
        }
        current->next = prev;
        return current;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* head = NULL;
        int last = 0; //进位
        while (l1 || l2)
        {
            int a(0);
            int b(0);
            if (l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            int append(0);
            if (a+b+last<=9)
            {
                append = a+b+last;
                last = 0; //进位清0
            }
            else
            {
                //进位
                append = a+b+last-10;
                last = 1;
            }
            ListNode *appendNode = new ListNode(0);
            appendNode->val = append;
            appendNode->next = NULL;
            if (!result)
            {
                result = appendNode;
                head = appendNode;
            }
            else
            {
                head->next = appendNode;
                head = appendNode;
            }
        }
        if (last)
        {
            ListNode *appendNode = new ListNode(0);
            appendNode->val = last;
            appendNode->next = NULL;
            head->next = appendNode;
            head = appendNode;
        }
        return result;
    }
};