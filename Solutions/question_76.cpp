class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (S.size() < T.size() || T.size() == 0)
			return "";

		vector<int> signature(256);
		vector<int> state(256);

		for (int i=0; i<T.size(); i++)
			signature[T[i]]++;

		int count = 0;
		int minStart = -1;
		int minEnd = S.size();

		for (int i=0; i<S.size(); i++) {
			if (signature[S[i]] > 0) {
				if (state[S[i]] < signature[S[i]]) {
					if (minStart == -1)
						minStart = i;
					count++;
					state[S[i]]++;
					if (count == T.size()) {
						minEnd = i;
						break;
					}
				} else {
					state[S[i]]++;
				}
			}
		}

		if (count < T.size())
			return "";

		while (true) {
			if (signature[S[minStart]] > 0) {
				if (signature[S[minStart]] == state[S[minStart]])
					break;
				else {
					state[S[minStart]]--;
				}
			}
			minStart++;
		}

		int curStart = minStart;
		for (int i=minEnd+1; i<S.size(); i++) {
			if (S[curStart] == S[i]) {
				curStart++;
				while (true) {
					if (signature[S[curStart]] > 0) {
						if (signature[S[curStart]] == state[S[curStart]])
							break;
						else {
							state[S[curStart]]--;
						}
					}
					curStart++;
				}

				if (i-curStart < minEnd-minStart) {
					minStart = curStart;
					minEnd = i;
				}
			} else {
				if (signature[S[i]] > 0)
					state[S[i]]++;
			}
		}

		return S.substr(minStart, minEnd-minStart+1);
    }
};
