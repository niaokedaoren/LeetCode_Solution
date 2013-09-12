/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	int len = listLen(head);

		return sortedListToBST(head, 0, len-1);
    }

private:
	int listLen(ListNode *head) {
		int count = 0;
		while (head) {
			count++;
			head = head->next;
		}

		return count;
	}

	TreeNode *sortedListToBST(ListNode *head, int left, int right) {
		if (right < left)
			return NULL;

		int mid = left + (right - left) / 2;
		int count = 0;
		ListNode* ptr = head;
		while (count < mid) {
			ptr = ptr->next;
			count++;
		}

		TreeNode *root = new TreeNode(ptr->val);
		root->left = sortedListToBST(head, left, mid-1);
		root->right = sortedListToBST(head, mid+1, right);

		return root;
	}
};
