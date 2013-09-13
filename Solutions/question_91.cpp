class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (s.size() == 0 || s[0] == '0')
			return 0;

		int first = 1;
		int second = 1;

		for (int i=1; i<s.size(); i++) {
			int cur = 0;
			if (s[i] != '0')
				cur += second;
			
			int temp = (s[i-1]-'0')*10 + (s[i]-'0');
			if (temp > 9 && temp <= 26)
				cur += first;

			first = second;
			second = cur;
		}
		
		return second;
    }
};

