class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string result(1, '0');
		for (int i=0; i<num1.size(); i++) {
			string part(i, '0');
			int cur = num1[i] - '0';
			int carry = 0;
			for (int j=0; j<num2.size(); j++) {
				int temp = (num2[j] - '0') * cur + carry;
				part.push_back('0' + temp % 10);
				carry = temp / 10;
			}

			if (carry)
				part.push_back('0' + carry);

			addToSum(result, part);
		}

		while (result.size() > 1 && result.back() == '0')
			result.pop_back();

		reverse(result.begin(), result.end());

		return result;
    }

private:
	void addToSum(string &sum, const string &num) {
		int carry = 0;
		int i = 0;
		while (i < sum.size() && i < num.size()) {
			int temp = (sum[i]-'0') + (num[i]-'0') + carry;
			sum[i] = '0' + temp % 10;
			carry = temp / 10;
			i++;
		}

		while (i < num.size()) {
			int temp = carry + (num[i]-'0');
			sum.push_back('0' + temp % 10);
			carry = temp / 10;
			i++;
		}

		while (i < sum.size()) {
			int temp = carry + (sum[i]-'0');
			sum[i] = '0' + temp % 10;
			carry = temp / 10;
			i++;
		}

		if (carry)
			sum.push_back('0' + carry);
	}
};
