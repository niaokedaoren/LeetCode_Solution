class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;

		int rows = grid.size();
		int cols = grid[0].size();
		vector<int> vec(cols);
		vector<vector<int> > state(2, vec);

		state[0][0] = grid[0][0];
		for (int j=1; j<cols; j++)
			state[0][j] = state[0][j-1] + grid[0][j];

		int cur = 0;
		int pre = 1;
		for (int i=1; i<rows; i++) {
			cur = !cur;
			pre = !pre;
			state[cur][0] = state[pre][0] + grid[i][0];
			for (int j=1; j<cols; j++) {
				int temp = min(state[pre][j], state[cur][j-1]);
				state[cur][j] = temp + grid[i][j];
			}
		}

		return state[cur].back();
    }
};
