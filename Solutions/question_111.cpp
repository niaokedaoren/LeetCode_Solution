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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 1;

		int curMin = INT_MAX;
		if (root->left)
			curMin = 1 + minDepth(root->left);

		if (root->right) {
			int temp = 1 + minDepth(root->right);
			if (temp < curMin)
				curMin = temp;
		}

		return curMin;
    }
};
