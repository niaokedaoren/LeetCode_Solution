class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
			return 0;

		if (obstacleGrid[0][0] == 1)
			return 0;

		int rows = obstacleGrid.size();
		int cols = obstacleGrid[0].size();
		vector<int> vec(cols);
		vector<vector<int> > state(2, vec);
		for (int j=0; j<cols; j++) {
			if (obstacleGrid[0][j] == 1)
				break;
			state[0][j] = 1;
		}

		int cur = 0;
		int pre = 1;
		for (int i=1; i<rows; i++) {
			cur = !cur;
			pre = !pre;
			if (obstacleGrid[i][0] == 1)
				state[cur][0] = 0;
			else
				state[cur][0] = state[pre][0];

			for (int j=1; j<cols; j++) {
				if (obstacleGrid[i][j] == 1)
					state[cur][j] = 0;
				else
					state[cur][j] = state[cur][j-1] + state[pre][j];
			}
		}

		return state[cur].back();
    }
};
