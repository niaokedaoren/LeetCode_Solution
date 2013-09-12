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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;
		vector<int> trace;

		pathSum(collection, trace, root, 0, sum);

		return collection;
    }

private:
	void pathSum(vector<vector<int> > &collection, vector<int> &trace, 
			TreeNode *root, int curSum, int target) {

		if (root == NULL)
			return;

		trace.push_back(root->val);
		curSum += root->val;

		if (root->left == NULL && root->right == NULL) {
			if (curSum == target)
				collection.push_back(trace);
		} else {
			pathSum(collection, trace, root->left, curSum, target);
			pathSum(collection, trace, root->right, curSum, target);
		}

		trace.pop_back();
	}
};
