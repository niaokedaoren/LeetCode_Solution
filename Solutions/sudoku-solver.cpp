class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		DFS(board, 0);
    }

private:
	bool DFS(vector<vector<char> > &board, int n) {
		if (n == size * size)
			return true;

		int x = n / size;
		int y = n % size;
		if (board[x][y] == '.') {
			for (int c=1; c<=9; c++) {
				if (!isConflict(board, x, y, '0'+c)) {
					board[x][y] = '0' + c;
					if (DFS(board, n+1))
						return true;
					board[x][y] = '.';
				}
			}
		} else
			return DFS(board, n+1);

		return false;
	}

	bool isConflict(const vector<vector<char> > &board, int x, int y, char val) {
		for (int i=0; i<size; i++) {
			if (board[i][y] == val)
				return true;
		}

		for (int j=0; j<size; j++) {
			if (board[x][j] == val)
				return true;
		}

		int blockX = x / 3;
		int blockY = y / 3;
		for (int i=blockX*3; i < (blockX+1)*3; i++) {
			for (int j=blockY*3; j < (blockY+1)*3; j++) {
				if (board[i][j] == val)
					return true;
			}
		}

		return false;
	}

	static const int size;
};

const int Solution::size = 9;
