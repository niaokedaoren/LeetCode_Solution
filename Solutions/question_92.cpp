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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (m == n)
			return head;

		ListNode *pre = NULL;
		ListNode *cur = head;
		int count = 1;
		while (count < m) {
			pre = cur;
			cur = cur->next;
			count++;
		}

		ListNode *tail1 = pre;
		ListNode *tail2 = cur;

		pre = NULL;
		while (count <= n) {
			ListNode *succ = cur->next;
			cur->next = pre;
			pre = cur;
			cur = succ;
			count++;
		}

		tail2->next = cur;
		if (tail1)
			tail1->next = pre;
		else
			head = pre;

		return head;
    }
};
