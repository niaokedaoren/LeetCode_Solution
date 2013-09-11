class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if (triangle.size() == 0)
			return 0;

		vector<int> state(triangle.size());
		state[0] = triangle[0][0];

		for (int n=1; n<triangle.size(); n++) {
			state[n] = state[n-1] + triangle[n].back();
			for (int i=n-1; i>0; i--) {
				int min = state[i] < state[i-1] ? state[i] : state[i-1];
				state[i] = min + triangle[n][i];
			}
			state[0] += triangle[n][0];
		}

		return *min_element(state.begin(), state.end());
    }
};
