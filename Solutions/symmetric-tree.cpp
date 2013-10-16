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
		// In order to copy a tree's symmetric, implementing in
		// a complicated way intentionally.

		if (root == NULL)
			return true;

		TreeNode *copiedRoot = new TreeNode(root->val);
		queue<TreeNode*> oriQueue;
		queue<TreeNode*> copiedQueue;
		oriQueue.push(root);
		copiedQueue.push(copiedRoot);
		while (!oriQueue.empty()) {
			TreeNode *oriTop = oriQueue.front();
			TreeNode *copiedTop = copiedQueue.front();
			oriQueue.pop();
			copiedQueue.pop();

			if (oriTop->right) {
				copiedTop->left = new TreeNode(oriTop->right->val);
				oriQueue.push(oriTop->right);
				copiedQueue.push(copiedTop->left);
			}

			if (oriTop->left) {
				copiedTop->right = new TreeNode(oriTop->left->val);
				oriQueue.push(oriTop->left);
				copiedQueue.push(copiedTop->right);
			}
		}

		bool result = isSameTree(root, copiedRoot);
		deleteTree(copiedRoot);

		return result;
    }

private:
	bool isSameTree(TreeNode *root1, TreeNode *root2) {
		if (root1 == NULL && root2== NULL)
			return true;

		if (root1 == NULL || root2 == NULL)
			return false;

		if (root1->val != root2->val)
			return false;

		return isSameTree(root1->left, root2->left) &&
			isSameTree(root1->right, root2->right);
	}

	void deleteTree(TreeNode *root) {
		if (root == NULL)
			return;

		deleteTree(root->left);
		deleteTree(root->right);

		delete root;
	}
};
