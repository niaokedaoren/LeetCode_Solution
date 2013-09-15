class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;
		vector<int> traces;

		if (k > n) {
			collection.push_back(traces);
			return collection;
		}

		DFS(collection, traces, 1, n, k);

		return collection;
    }

private:
	void DFS(vector<vector<int> > &collection, vector<int> &traces,
			int start, int n, int k) {

		if (traces.size() == k) {
			collection.push_back(traces);
			return;
		}

		if (n-start+1+traces.size() < k)
			return;

		for (int i=start; i<=n; i++) {
			traces.push_back(i);
			DFS(collection, traces, i+1, n, k);
			traces.pop_back();
		}
	}
};
