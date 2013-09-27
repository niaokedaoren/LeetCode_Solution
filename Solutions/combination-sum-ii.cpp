class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;
		if (num.size() == 0)
			return collection;

		sort(num.begin(), num.end());
		vector<int> traces;

		DFS(collection, traces, num, 0, target);

		return collection;
    }

private:
	void DFS(vector<vector<int> > &collection, vector<int> &traces, 
			vector<int> &num, int n, int remain) {

		if (remain == 0 && traces.size() > 0) {
			collection.push_back(traces);
			return;
		}

		if (n >= num.size())
			return;

		if (remain >= num[n]) {
			traces.push_back(num[n]);
			DFS(collection, traces, num, n+1, remain-num[n]);
			traces.pop_back();

			n++;
			while (n<num.size() && num[n] == num[n-1])
				n++;

			DFS(collection, traces, num, n, remain);
		}
	}
};
