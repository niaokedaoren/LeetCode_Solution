class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int left = 0;
		int right = s.size() - 1;

		while (left < right) {
			while (left < right && !isalnum(s[left]))
				left++;
			while (left < right && !isalnum(s[right]))
				right--;

			if (left >= right)
				break;

			char leftChar = s[left];
			char rightChar = s[right];
			if (isalpha(leftChar))
				leftChar = tolower(leftChar);
			if (isalpha(rightChar))
				rightChar = tolower(rightChar);

			if (leftChar != rightChar)
				return false;

			left++;
			right--;
		}

		return true;
    }
};
