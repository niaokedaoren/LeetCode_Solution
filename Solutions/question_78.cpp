class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > sets(1, vector<int>());
		sort(S.begin(), S.end());

		for (int n=0; n<S.size(); n++) {
			int preSize = sets.size();
			for (int i=0; i<preSize; i++) {
				sets.push_back(sets[i]);
				sets.back().push_back(S[n]);
			}
		}

		return sets;
    }
};
