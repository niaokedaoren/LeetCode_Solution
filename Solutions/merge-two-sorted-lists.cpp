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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (l1 == NULL)
			return l2;

		if (l2 == NULL)
			return l1;

		ListNode *head = NULL;
		if (l1->val <= l2->val) {
			head = l1;
			l1 = l1->next;
		} else {
			head = l2;
			l2 = l2->next;
		}

		ListNode *ptr = head;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				ptr->next = l1;
				l1 = l1->next;
			} else {
				ptr->next = l2;
				l2 = l2->next;
			}

			ptr = ptr->next;
		}

		ListNode *rest = l1 ? l1 : l2;
		while (rest) {
			ptr->next = rest;
			ptr = ptr->next;
			rest = rest->next;
		}

		return head;
    }
};
