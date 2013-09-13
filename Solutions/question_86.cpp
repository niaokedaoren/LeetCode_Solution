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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (head == NULL)
			return head;

		ListNode *lessHead = NULL;
		ListNode *geHead = NULL;
		ListNode *lessPtr, *gePtr;

		while (head) {
			if (head->val < x) {
				if (lessHead == NULL) {
					lessHead = head;
					lessPtr = head;
				} else {
					lessPtr->next = head;
					lessPtr = lessPtr->next;
				}
			} else {
				if (geHead == NULL) {
					geHead = head;
					gePtr = head;
				} else {
					gePtr->next = head;
					gePtr = gePtr->next;
				}
			}

			head = head->next;
		}

		if (lessHead) {
			lessPtr->next = geHead;
			if (geHead)
				gePtr->next = NULL;
			return lessHead;
		} else
			return geHead;
    }
};
