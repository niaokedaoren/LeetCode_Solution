class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<bool> used(n);
		int base = 1;
		for (int i=1; i<n; i++)
			base *= i;

		int step = n - 1;
		string permutation = "";
		while (step > 0) {
			int index = (k - 1) / base + 1;
			int count = 0;
			for (int i=0; i<n; i++) {
				if (used[i] == false) {
					count++;
					if (count == index) {
						used[i] = true;
						permutation.push_back('0' + i + 1);
						break;
					}
				}
			}

			k = k - base*(index-1);
			base /= step;
			step--;
		}

		for (int i=0; i<n; i++) {
			if (used[i] == false) {
				permutation.push_back('0' + i + 1);
				break;
			}
		}

		return permutation;
    }
};
