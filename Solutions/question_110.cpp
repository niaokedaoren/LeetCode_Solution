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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int height = 0;

		return isBalanced(root, height);
    }

private:
	bool isBalanced(TreeNode *root, int &height) {
		if (root == NULL) {
			return true;
		}

		int leftHeight = 0;
		int rightHeight = 0;

		if (isBalanced(root->left, leftHeight) && isBalanced(root->right, rightHeight)) {
			height = max(leftHeight, rightHeight) + 1;
			if (abs(leftHeight - rightHeight) <= 1)
				return true;
		}

		return false;
	}
};
