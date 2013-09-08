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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int total = 0;
		sumNumbers(root, 0, total);

		return total;
    }

private:
	void sumNumbers(TreeNode *root, int pathSum, int &total) {
		if (root == NULL)
			return;
		
		pathSum = pathSum * 10 + root->val;
		if (root->left == NULL && root->right == NULL) {
			total += pathSum;
			return;
		}

		sumNumbers(root->left, pathSum, total);
		sumNumbers(root->right, pathSum, total);
	}
};
