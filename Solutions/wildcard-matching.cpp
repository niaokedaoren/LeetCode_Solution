class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (s == NULL && p == NULL)
			return true;
		else if (s == NULL || p == NULL)
			return false;

		int sLen = strlen(s);
		if (sLen < minLen(p))
			return false;
		int pLen = strlen(p);

		vector<vector<bool> > state(2, vector<bool>(pLen+1));
		vector<bool> hasTrue(pLen+1);
		int cur = 0;
		int pre = 1;
		hasTrue[0] = true;
		state[cur][0] = true;
		for (int j=0; j < pLen && p[j] == '*'; j++) {
			state[cur][j+1] = true;
			hasTrue[j+1] = true;
		}

		for (int i=0; i<sLen; i++) {
			cur = !cur;
			pre = !pre;
			state[cur][0] = false;
			for (int j=0; j<pLen; j++) {
				if (p[j] == '*') {
					if (hasTrue[j])
						state[cur][j+1] = true;
					else
						state[cur][j+1] = false;
				} else if (p[j] == '?') {
					state[cur][j+1] = state[pre][j];
				} else {
					if (s[i] == p[j])
						state[cur][j+1] = state[pre][j];
					else
						state[cur][j+1] = false;
				}

				if (state[cur][j+1])
					hasTrue[j+1] = true;
			}
		}

		return state[cur].back();
    }

private:
	int minLen(const char *p) {
		int len = 0;
		while (*p) {
			if (*p != '*')
				len++;

			p++;
		}

		return len;
	}
};
