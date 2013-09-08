class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<int> vec;
		vector<vector<int> > palinLen(s.size() + 1, vec);
		palinLen[0].push_back(0);

		for (int n=0; n<s.size(); n++) {
			palinLen[n+1].push_back(0);
			palinLen[n+1].push_back(1);

			for (int i=0; i<palinLen[n].size(); i++) {
				int len = palinLen[n][i];
				if (n-len > 0 && s[n-1-len] == s[n]) {
					palinLen[n+1].push_back(len+2);
				}
			}
		}

		vector<vector<string> > collection;
		vector<string> trace;

		constructPartitions(collection, trace, s.size(), palinLen, s);

		return collection;
    }

private:
	void constructPartitions(vector<vector<string> > &collection, vector<string> &trace,
		int length, const vector<vector<int> > &palinLen, const string &s) {

		if (length == 0) {
			reverse(trace.begin(), trace.end());
			collection.push_back(trace);
			reverse(trace.begin(), trace.end());
			return;
		}

		for (int i=1; i<palinLen[length].size(); i++) {
			int len = palinLen[length][i];
			trace.push_back(s.substr(length-len, len));
			constructPartitions(collection, trace, length-len, palinLen, s);
			trace.pop_back();
		}
	}
};
