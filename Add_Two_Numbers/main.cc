/**
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

/**
 * 考察加法进位
 * 一开始错误的思路是把list转为int再相加，再装为list，这样会有溢出问题
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int carry = 0;
    	int sum = 0;
    	ListNode *head = NULL;
    	ListNode *p = NULL;
        while (l1 || l2 || carry){
        	sum = carry;
        	carry = 0;
        	if (l1){
        		sum += l1->val;
        		l1 = l1->next;
        	}
        	if (l2){
        		sum += l2->val;
        		l2 = l2->next;
        	}
        	if (sum > 9){
        		carry = 1;
        		sum = sum - 10;
        	}
        	ListNode *currentNode = new ListNode(sum);
        	if (head == NULL){
        		head = currentNode;
        		p = head;
        	} else {
        		p->next = currentNode;
        		p = currentNode;
        	}
        }
        return head;
    }

    void printList(ListNode* l){
    	while (l){
    		cout << l->val;
    		if (l->next){
    			cout << " -> ";
    		}
    		l = l->next;
    	}
    	cout << endl;
    }

    void deleteList(ListNode* l){
    	ListNode *prev = NULL;
    	while (l){
    		prev = l->next;
    		l->next = NULL;
    		delete(l);
    		l = prev;
    	}
    }
};

int main(){
	return 0;
}