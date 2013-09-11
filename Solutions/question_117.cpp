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
		while (leftMost) {
			TreeLinkNode *parent = leftMost;
			while (parent) {
				if (parent->left) {
					leftMost = parent->left;
					break;
				} else if (parent->right) {
					leftMost = parent->right;
					break;
				}

				parent = parent->next;
			}

			if (parent == NULL)
				return;

			TreeLinkNode *pre = leftMost;

			while (parent) {
				if (parent->left && pre != parent->left) {
					pre->next = parent->left;
					pre = pre->next;
				}

				if (parent->right && pre != parent->right) {
					pre->next = parent->right;
					pre = pre->next;
				}

				parent = parent->next;
			}
		}

    }
};
