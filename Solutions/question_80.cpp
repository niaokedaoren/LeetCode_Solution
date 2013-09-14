class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (n <= 2)
			return n;

		int pivot = 1;
		for (int i=2; i<n; i++) {
			if (A[pivot] != A[i])
				A[++pivot] = A[i];
			else {
				if (A[pivot-1] != A[i])
					A[++pivot] = A[i];
			}
		}

		return ++pivot;
    }
};
