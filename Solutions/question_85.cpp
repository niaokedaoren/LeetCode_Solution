class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;

		int raws = matrix.size();
		int cols = matrix[0].size();

		vector<vector<int> > board(raws, vector<int>(cols));
		for (int j=0; j<cols; j++)
			if (matrix[raws-1][j] == '1')
				board[raws-1][j] = 1;

		for (int i=raws-2; i>=0; i--) {
			for (int j=0; j<cols; j++) {
				if (matrix[i][j] == '1')
					board[i][j] = board[i+1][j] + 1;
			}
		}

		int max = 0;
		stack<int> incSeq;
		for (int i=0; i<raws; i++) {
		}
    }
};
