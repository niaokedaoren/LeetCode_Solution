class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<int> codes(1);
		if (n == 0)
			return codes;

		codes.push_back(1);

		int base = 1;
		for (int i=1; i<n; i++) {
			base *= 2;
			int preSize = codes.size();
			for (int j=preSize-1; j>=0; j--) {
				codes.push_back(codes[j]+base);
			}
		}

		return codes;
    }
};
