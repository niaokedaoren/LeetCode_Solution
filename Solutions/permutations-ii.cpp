class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;
		int size = num.size();
		if (size == 0)
			return collection;

		sort(num.begin(), num.end());
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

		bool isFirst = true;
		int pre;
		for (int i=0; i<used.size(); i++) {
			if (used[i] == false) {
				if (isFirst == false && pre == num[i])
					continue;

				isFirst = false;
				pre = num[i];
				used[i] = true;
				traces.push_back(num[i]);
				DFS(collection, traces, used, num);
				used[i] = false;
				traces.pop_back();
			}
		}
	}
};
