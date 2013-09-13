class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		return isScramble(s1, 0, s1.size()-1, s2, 0, s2.size()-1);
    }

private:
	bool isScramble(const string &s1, int left1, int right1,
			const string &s2, int left2, int right2) {

		if (left1 > right1)
			return true;

		int signature1[26] = {0};
		int signature2[26] = {0};
		int len = right1 - left1 + 1;
		for (int i=0; i<len; i++) {
			signature1[s1[left1+i] - 'a']++;
			signature2[s2[left2+i] - 'a']++;
		}

		for (int n=0; n<26; n++)
			if (signature1[n] != signature2[n])
				return false;

		if (len == 1)
			return true;

		for (int i=0; i<len-1; i++) {
			if ((isScramble(s1, left1, left1+i, s2, left2, left2+i) && 
					isScramble(s1, left1+i+1, right1, s2, left2+i+1, right2)) || 
				(isScramble(s1, left1, left1+i, s2, right2-i, right2) &&
					isScramble(s1, left1+i+1, right1, s2, left2, right2-i-1)))
				return true;
		}

		return false;
	}
};
