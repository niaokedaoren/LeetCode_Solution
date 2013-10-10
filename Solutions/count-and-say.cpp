class Solution {
public:
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		if (n <= 0)
			return "";

		string pre, cur;
		pre = "1";
		for (int i=1; i<n; i++) {
			cur = "";
			int count = 1;
			char c = pre[0];
			for (int j=1; j<pre.size(); j++) {
				if (pre[j] != c) {
					cur += itoa(count);
					cur.push_back(c);
					count = 1;
					c = pre[j];
				} else
					count++;
			}

			if (count > 0) {
				cur += itoa(count);
				cur.push_back(c);
			}

			pre = cur;
		}

		return pre;
    }

private:
	string itoa(int num) {
		string temp;
		while (num) {
			temp.push_back('0' + num%10);
			num /= 10;
		}

		reverse(temp.begin(), temp.end());

		return temp;
	}
};
