class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (n <= 1)
			return 0;

		int preEnd = 0;
		int curEnd = A[0];
		int step = 1;
		while (curEnd < n-1 && curEnd > preEnd) {
			int i = preEnd + 1;
			preEnd = curEnd;
			while (i <= preEnd) {
				if (i + A[i] > curEnd)
					curEnd = i + A[i];
				i++;
			}

			step++;
		}

		return step;
    }
};
