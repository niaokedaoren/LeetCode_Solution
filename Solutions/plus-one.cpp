class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		reverse(digits.begin(), digits.end());

		int carry = 1;
		for (int i=0; i<digits.size(); i++) {
			int sum = carry + digits[i];
			digits[i] = sum % 10;
			carry = sum / 10;
		}

		if (carry)
			digits.push_back(carry);

		reverse(digits.begin(), digits.end());

		return digits;
    }
};
