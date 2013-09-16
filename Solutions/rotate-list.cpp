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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (head == NULL || k == 0)
			return head;

		int len = 0;
		ListNode *cur = head;
		ListNode *pre = NULL;
		while (cur) {
			pre = cur;
			cur = cur->next;
			len++;
		}

		k %= len;
		if (k == 0)
			return head;

		ListNode *tail = pre;
		cur = head;
		int count = 1;
		while (count < len - k) {
			cur = cur->next;
			count++;
		}

		ListNode *newHead = cur->next;
		cur->next = NULL;
		tail->next = head;

		return newHead;
    }
};
