class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;
		int size = num.size();
		if (size == 0)
			return collection;

		vector<bool> used(size);
		vector<int> traces;

		DFS(collection, traces, used, num);

		return collection;
    }

private:
	void DFS(vector<vector<int> > &collection, vector<int> &traces,
			vector<bool> &used, const vector<int> &num) {

		if (traces.size() == num.size()) {
			collection.push_back(traces);
			return;
		}

		for (int i=0; i<used.size(); i++) {
			if (used[i] == false) {
				used[i] = true;
				traces.push_back(num[i]);
				DFS(collection, traces, used, num);
				used[i] = false;
				traces.pop_back();
			}
		}
	}
};
