class Solution {
	public:
		int minCut(string s) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function

			if (s.size() == 0)
				return 0;

			vector<int> state(s.size() + 1);
			vector<int> vec;
			vector<vector<int> > palinLen(2, vec);

			int cur = 0;
			int pre = 1;
			state[0] = 0;
			palinLen[cur].push_back(0);
			for (int n=0; n<s.size(); n++) {
				cur = !cur;
				pre = !pre;

				palinLen[cur].clear();
				palinLen[cur].push_back(0);
				palinLen[cur].push_back(1);

				int min = state[n] + 1;
				for (int i=0; i<palinLen[pre].size(); i++) {
					int len = palinLen[pre][i];
					if (n - 1 - len < 0)
						break;
					
					if (s[n-1-len] == s[n]) {
						palinLen[cur].push_back(len + 2);
						if (state[n-1-len] + 1 < min)
							min = state[n-1-len] + 1;
					}
				}

				state[n+1] = min;
			}

			return state[s.size()] - 1;
		}
};
