class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		string result = "";
		int carry = 0;
		int i = 0;
		while (i<a.size() && i<b.size()) {
			int sum = (a[i]-'0') + (b[i]-'0') + carry;
			result.push_back('0' + sum%2);
			carry = sum / 2;
			i++;
		}

		while (i < a.size()) {
			int sum = (a[i]-'0') + carry;
			result.push_back('0' + sum%2);
			carry = sum / 2;
			i++;
		}
		
		while (i < b.size()) {
			int sum = (b[i]-'0') + carry;
			result.push_back('0' + sum%2);
			carry = sum / 2;
			i++;
		}

		if (carry)
			result.push_back('1');

		reverse(result.begin(), result.end());

		return result;
    }
};
