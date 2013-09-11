/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		TreeLinkNode *leftMost = root;
		while (leftMost && leftMost->left) {
			TreeLinkNode *parent = leftMost;
			leftMost = leftMost->left;

			TreeLinkNode *pre = leftMost;
			pre->next = parent->right;
			pre = pre->next;
			parent = parent->next;

			while (parent) {
				pre->next = parent->left;
				pre = pre->next;
				pre->next = parent->right;
				pre = pre->next;

				parent = parent->next;
			}
		}
    }
};
