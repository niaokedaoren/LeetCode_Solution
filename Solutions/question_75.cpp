class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int left = 0;
		int right = n - 1;

		for (int i=0; i<=right; ) {
			if (A[i] == 0) {
				A[i] = A[left];
				A[left++] = 0;
				i++;
			} else if (A[i] == 2) {
				A[i] = A[right];
				A[right--] = 2;
			} else
				i++;
		}
    }
};
