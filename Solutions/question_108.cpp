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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		return sortedArrayToBST(num, 0, num.size()-1);
    }

private:
	TreeNode *sortedArrayToBST(const vector<int> &num, int left, int right) {
		if (right < left)
			return NULL;

		int mid = left + (right - left) / 2;
		TreeNode *root = new TreeNode(num[mid]);
		root->left = sortedArrayToBST(num, left, mid-1);
		root->right = sortedArrayToBST(num, mid+1, right);

		return root;
	}
};
