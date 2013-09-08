class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if (board.size() == 0)
			return;
		
		int rows = board.size();
		int cols = board[0].size();

		for (int i=0; i<rows; i++) {
			if (board[i][0] == 'O')
				markBorder(board, i, 0);
			
			if (cols > 1 && board[i][cols-1] == 'O')
				markBorder(board, i, cols-1);
		}

		for (int j=0; j<cols; j++) {
			if (board[0][j] == 'O')
				markBorder(board, 0, j);

			if (rows > 1 && board[rows-1][j] == 'O')
				markBorder(board, rows-1, j);
		}

		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols; j++) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == MARK)
					board[i][j] = 'O';	
			}
		}
    }

private:
	const char MARK = '#';

	void markBorder(vector<vector<char> > &board, int x, int y) {
		int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
		int rows = board.size();
		int cols = board[0].size();

		queue<int> coords;
		coords.push(x*cols + y);
		board[x][y] = MARK;
		while (!coords.empty()) {
			int temp = coords.front();
			coords.pop();
			x = temp / cols;
			y = temp % cols;
			for (int i=0; i<4; i++) {
				int curX = x + dir[i][0];
				int curY = y + dir[i][1];

				if (curX >= 0 && curX < rows && curY >= 0 && curY < cols &&
						board[curX][curY] == 'O') {
					board[curX][curY] = MARK;
					coords.push(curX*cols + curY);
				}
			}
		}
	}
};
