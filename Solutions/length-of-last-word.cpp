class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (s == NULL || *s == '\0')
			return 0;

		bool inSpace = true;
		bool inWord = false;
		int start = -1;
		int end = -1;
		int count = 0;

		while (*s) {
			count++;
			if (*s == ' ') {
				if (inWord) {
					end = count;
					inWord = false;
				}
				
				inSpace = true;
			} else {
				if (inSpace) {
					start = count;
					inSpace = false;
				}

				inWord = true;
			}

			s++;
		}

		if (inWord)
			end = count + 1;

		return end - start;
    }
};
