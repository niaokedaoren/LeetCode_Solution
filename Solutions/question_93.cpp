class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	vector<string> collection;
		vector<string> traces;

		DFS(collection, traces, s, 0);

		return collection;
    }

private:
	void DFS(vector<string> &collection, vector<string> &traces,
			const string &s, int n) {

		if (n == s.size()) {
			if (traces.size() != 4)
				return;

			string ip = traces[0];
			for (int i=1; i<4; i++) {
				ip.push_back('.');
				ip += traces[i];
			}

			collection.push_back(ip);
			return;
		} else if (traces.size() >= 4) {
			return;
		}

		int borders[4] = {0, 10, 100, 256};
		int val = 0;
		for (int i=0; i<3 && n+i<s.size(); i++) {
			val = val * 10 + (s[n+i] - '0');
			if (val >= borders[i] && val < borders[i+1]) {
				traces.push_back(s.substr(n, i+1));
				DFS(collection, traces, s, n+i+1);
				traces.pop_back();
			}
		}
	}
};

