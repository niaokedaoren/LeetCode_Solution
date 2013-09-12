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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;
		if (root == NULL)
			return collection;
		
		vector<int> row;
		stack<TreeNode*> layer;
		vector<stack<TreeNode*> > layers(2, layer);

		int cur = 0;
		int pre = 1;
		bool leftFirst = false;
		layers[cur].push(root);
		
		while (!layers[cur].empty()) {
			cur = !cur;
			pre = !pre;
			leftFirst = !leftFirst;
			row.clear();

			while (!layers[pre].empty()) {
				TreeNode *ptr = layers[pre].top();
				layers[pre].pop();

				row.push_back(ptr->val);

				if (leftFirst) {
					if (ptr->left)
						layers[cur].push(ptr->left);
					if (ptr->right)
						layers[cur].push(ptr->right);
				} else {
					if (ptr->right)
						layers[cur].push(ptr->right);
					if (ptr->left)
						layers[cur].push(ptr->left);
				}
			}

			collection.push_back(row);
		}

		return collection;
    }
};
