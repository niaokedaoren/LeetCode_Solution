class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int first = 1;
		int second = 1;
		
		for (int i=1; i<n; i++) {
			int cur = first + second;
			first = second;
			second = cur;
		}

		return second;
    }
};
