class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if (m <= 0 || m <= 0)
			return 0;
        
		long long larger = max(m-1, n-1);
		long long smaller = min(m-1, n-1);

		long long temp1 = 1;
		long long temp2 = 1;

		for (long long i=1; i<=smaller; i++)
			temp1 *= i;

		for (long long i=larger+1; i <= smaller+larger; i++)
			temp2 *= i;

		return (int)(temp2 / temp1);
    }
};
