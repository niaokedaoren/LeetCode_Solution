class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (num.size() <= 1)
			return num.size();

		unordered_set<int> numSet;
		numSet.insert(num.begin(), num.end());

		int maxLen = 0;
		while (numSet.size() > maxLen) {
			int cur = *numSet.begin();
			int count = 1;
			numSet.erase(cur);

			for (int n=cur-1; numSet.count(n) > 0; n--) {
				count++;
				numSet.erase(n);
			}

			for (int n=cur+1; numSet.count(n) > 0; n++) {
				count++;
				numSet.erase(n);
			}

			if (count > maxLen)
				maxLen = count;
		}

		return maxLen;
    }
};
