/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
		if (head == NULL)
			return NULL;

		RandomListNode *cur = head;
		RandomListNode *succ = NULL;

		while (cur) {
			succ = cur->next;
			cur->next = new RandomListNode(cur->label);
			cur->next->next = succ;
			cur = succ;
		}

		RandomListNode *copiedCur = NULL;
		cur = head;
		while (cur) {
			if (cur->random) {
				copiedCur = cur->next;
				copiedCur->random = cur->random->next;
			}

			cur = cur->next->next;
		}

		RandomListNode *copiedHead = NULL;
		cur = head;
		while (cur) {
			succ = cur->next->next; 
			if (copiedHead == NULL) {
				copiedHead = cur->next;
				copiedCur = cur->next; 
			} else {
				copiedCur->next = cur->next;
				copiedCur = copiedCur->next;
			}

			cur->next = succ;
			cur = succ;
		}

		return copiedHead;
    }
};
