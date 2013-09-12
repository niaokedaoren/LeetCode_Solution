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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		TreeNode *prev = NULL;

		flatten(root, prev);
    }

private:
	void flatten(TreeNode *root, TreeNode *&prev) {
		if (root == NULL)
			return;

		TreeNode *leftSub = root->left;
		TreeNode *rightSub = root->right;
		root->left = NULL;

		if (prev == NULL)
			prev = root;
		else {
			prev->right = root;
			prev = prev->right;
		}

		flatten(leftSub, prev);
		flatten(rightSub, prev);
	}
};
