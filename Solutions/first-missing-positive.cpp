class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (n <= 0)
			return 1;

		for (int i=0; i<n; i++) {
			if (A[i] <= 0 || A[i] > n) {
				A[i] = 0;
			} else {
				if (A[i] == i + 1)
					continue;

				int cur = A[i];
				A[i] = 0;
				while (cur>0 && cur<=n && A[cur-1] != cur) {
					int temp = A[cur-1];
					A[cur-1] = cur;
					cur = temp;
				}
			}
		}

		for (int i=0; i<n; i++)
			if (A[i] == 0)
				return i+1;

		return n+1;
    }
};
