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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		return generateTrees(1, n);
    }

private:
	vector<TreeNode *> generateTrees(int left, int right) {
		vector<TreeNode *> trees;

		if (right < left) {
			trees.push_back(NULL);
			return trees;
		}

		for (int i=left; i<=right; i++) {
			auto leftSubtrees = generateTrees(left, i-1);
			auto rightSubtrees = generateTrees(i+1, right);

			for (int x=0; x<leftSubtrees.size(); x++) {
				for (int y=0; y<rightSubtrees.size(); y++) {
					TreeNode *root = new TreeNode(i);
					root->left = leftSubtrees[x];
					root->right = rightSubtrees[y];
					trees.push_back(root);
				}
			}
		}

		return trees;
	}
};
