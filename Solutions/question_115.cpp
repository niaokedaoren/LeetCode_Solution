class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if (S.size() < T.size())
			return 0;
        
		vector<int> state(T.size() + 1);
		state[0] = 1;

		for (int i=0; i<S.size(); i++) {
			for (int j=T.size()-1; j>=0; j--) {
				if (T[j] == S[i])
					state[j+1] += state[j];
			}
		}

		return state.back();
    }
};
