class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;

		if (candidates.size() == 0)
			return collection;

		sort(candidates.begin(), candidates.end());
		vector<int> traces;
		DFS(collection, traces, candidates, 0, target);

		return collection;
    }

private:
	void DFS(vector<vector<int> > &collection, vector<int> &traces, 
			vector<int> &candidates, int n, int remain) {

		if (remain == 0 && traces.size() > 0) {
			collection.push_back(traces);
			return;
		}

		if (n >= candidates.size())
			return;

		int count = remain / candidates[n];
		for (int i=0; i<=count; i++) {
			int temp = i * candidates[n];
			DFS(collection, traces, candidates, n+1, remain-temp);
			traces.push_back(candidates[n]);
		}

		while (traces.size() > 0 && traces.back() == candidates[n]) {
			traces.pop_back();
		}
	}
};
