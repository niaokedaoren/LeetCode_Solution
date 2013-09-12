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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (root == NULL)
			return true;

		return isSymmetric(root->left, root->right);
    }

private:
	bool isSymmetric(TreeNode *leftSub, TreeNode *rightSub) {
		if (leftSub == NULL && rightSub == NULL)
			return true;
		else if (leftSub && rightSub) {
			if (leftSub->val == rightSub->val)
				return isSymmetric(leftSub->left, rightSub->right) && 
					isSymmetric(leftSub->right, rightSub->left);
		}

		return false;
	}
};
