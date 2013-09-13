class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;
		vector<int> subset;
		collection.push_back(subset);

		sort(S.begin(), S.end());

		int n = 0;
		while (n < S.size()) {
			int preSize = collection.size();

			for (int i=0; i<preSize; i++) {
				collection.push_back(collection[i]);
				collection.back().push_back(S[n]);
			}

			int k;
			for (k=1; k+n<S.size(); k++) {
				if (S[n+k] != S[n])
					break;

				for (int i=preSize*k; i<preSize*(k+1); i++) {
					collection.push_back(collection[i]);
					collection.back().push_back(S[n]);
				}
			}

			n += k;
		}

		return collection;
    }
};
