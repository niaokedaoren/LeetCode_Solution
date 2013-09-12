class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
		if (s1.size() + s2.size() != s3.size())
			return false;

		vector<bool> vec(s2.size() + 1);
		vector<vector<bool> > state(2, vec);
		int cur = 0;
		int pre = 1;
		state[cur][0] = true;
		for (int j=0; j<s2.size(); j++) {
			if (s3[j] == s2[j])
				state[cur][j+1] = true;
			else
				break;
		}

		for (int i=0; i<s1.size(); i++) {
			cur = !cur;
			pre = !pre;
			if (s1[i] == s3[i])
				state[cur][0] = state[pre][0];
			else
				state[cur][0] = false;

			for (int j=0; j<s2.size(); j++) {
				char c = s3[i+j+1];
				if (s1[i] == c && s2[j] == c)
					state[cur][j+1] = state[pre][j+1] || state[cur][j];
				else if (s1[i] == c)
					state[cur][j+1] = state[pre][j+1];
				else if (s2[j] == c)
					state[cur][j+1] = state[cur][j];
				else
					state[cur][j+1] = false;
			}
		}

		return state[cur].back();
    }
};
