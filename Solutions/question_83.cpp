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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *pre = head;
		ListNode *cur = head->next;
		while (cur) {
			ListNode *succ = cur->next;
			if (pre->val == cur->val)
				delete cur;
			else {
				pre->next = cur;
				pre = pre->next;
			}

			cur = succ;
		}

		pre->next = NULL;

		return head;
    }
};
