class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (n == 0)
			return;

		int end = m + n - 1;
		m--;
		n--;
		while (m>=0 && n>=0) {
			if (A[m] <= B[n])
				A[end--] = B[n--];
			else
				A[end--] = A[m--];
		}

		while (n>=0)
			A[end--] = B[n--];
    }
};
