class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		if (s.size() == 0)
			return false;

		vector<bool> state(s.size() + 1);
		state[0] = true;
		string tailWord;

		for (int n=0; n<s.size(); n++) {
			for (int i=n; i>=0; i--) {
				if (state[i]) {
					tailWord = s.substr(i, n-i+1);
					if (dict.count(tailWord) > 0) {
						state[n+1] = true;
						break;
					}
				}
			}
		}

		return state.back();
    }
};
