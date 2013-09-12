class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (n <= 1)
			return n;

		vector<int> treeNum(n+1);
		treeNum[0] = 1;
		treeNum[1] = 1;

		for (int i=2; i<=n; i++) {
			for (int k=1; k<=i; k++) {
				treeNum[i] += treeNum[k-1] * treeNum[i-k];
			}
		}

		return treeNum.back();
    }
};
