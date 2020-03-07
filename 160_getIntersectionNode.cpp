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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_map<ListNode*, int> hash;
        ListNode *p = headA;
        while (p)
        {
            hash[p] = 1;
            p = p->next;
        }
        p = headB;
        while (p)
        {
            if (hash.find(p) != hash.end())
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
};
