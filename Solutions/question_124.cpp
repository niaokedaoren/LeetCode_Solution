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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int maxSum = INT_MIN;
		getSubSum(root, maxSum);

		return maxSum;
    }

private:
	int getSubSum(TreeNode *root, int &maxSum) {
		if (root == NULL)
			return 0;

		int leftMax = INT_MIN;
		int rightMax = INT_MIN;

		int leftSubSum = getSubSum(root->left, leftMax);
		int rightSubSum = getSubSum(root->right, rightMax);

		maxSum = leftMax > rightMax ? leftMax : rightMax;
		
		int curSum = leftSubSum + rightSubSum + root->val;
		if (curSum > maxSum)
			maxSum = curSum;

		leftSubSum += root->val;
		rightSubSum += root->val;

		int temp = leftSubSum > rightSubSum ? leftSubSum : rightSubSum;

		return temp > 0 ? temp : 0;
	}
};
