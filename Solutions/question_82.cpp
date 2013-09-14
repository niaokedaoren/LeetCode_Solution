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

		ListNode *ptr = head;
		ListNode *tail = NULL;
		head = NULL;

		while (ptr) {
			int count = 1;
			while (ptr->next) {
				if (ptr->val != ptr->next->val)
					break;
				count++;
				ptr = ptr->next;
			}

			if (count == 1) {
				if (head == NULL) {
					head = tail = ptr;
				} else {
					tail->next = ptr;
					tail = tail->next;
				}
			}

			ptr = ptr->next;
		}

		if (head)
			tail->next = NULL;

		return head;
    }
};
