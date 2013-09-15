class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<int> vec(word2.size() + 1);
		vector<vector<int> > state(word1.size() + 1, vec);

		for (int j=0; j<word2.size(); j++)
			state[0][j+1] = j+1;

		for (int i=0; i<word1.size(); i++) {
			state[i+1][0] = i+1;
			for (int j=0; j<word2.size(); j++) {
				if (word1[i] == word2[j])
					state[i+1][j+1] = state[i][j];
				else {
					int temp = min(state[i][j+1], state[i+1][j]);
					state[i+1][j+1] = min(state[i][j], temp) + 1;
				}
			}
		}

		return state[word1.size()][word2.size()];
    }
};
