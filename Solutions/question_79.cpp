class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if (board.size() == 0 || word.size() == 0)
			return word.size() == 0;

		int rows = board.size();
		int cols = board[0].size();
        
		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols; j++) {
				if (board[i][j] != word[0])
					continue;

				board[i][j] = USED;
				if (exist(board, word, i, j, 1))
					return true;
				board[i][j] = word[0];
			}
		}
    }

private:
	bool exist(vector<vector<char> > &board, const string &word,
			int x, int y, int n) {

		if (word.size() == n)
			return true;

		int rows = board.size();
		int cols = board[0].size();

		for (int i=0; i<4; i++) {
			int curX = x + dir[i][0];
			int curY = y + dir[i][1];
			if (curX>=0 && curX<rows && curY>=0 && curY<cols &&
					board[curX][curY] == word[n]) {
				board[curX][curY] = USED;
				if (exist(board, word, curX, curY, n+1))
					return true;
				board[curX][curY] = word[n];
			}
		}

		return false;
	}

	static const char USED;
	static const int dir[4][2];
};

const char Solution::USED = '*';
const int Solution::dir[4][2] = {
	{0, -1}, {-1, 0}, {0, 1}, {1, 0}
};
