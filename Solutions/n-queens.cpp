class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<string> > collection;

		if (n <= 0)
			return collection;

		string row(n, '.');
		vector<string> board(n, row);

		DFS(collection, board, 0, n);

		return collection;
    }

private:
	void DFS(vector<vector<string> > &collection, 
			vector<string> &board, int cur, int n) {

		if (cur == n) {
			collection.push_back(board);
			return;
		}

		for (int x=0; x<n; x++) {
			if (isConflict(board, x, cur) == false) {
				board[x][cur] = 'Q';
				DFS(collection, board, cur+1, n);
				board[x][cur] = '.';
			}
		}
	}

	bool isConflict(const vector<string> &board, int x, int y) {
		int size = board.size();

		for (int i=0; i<size; i++)
			if (board[i][y] == 'Q')
				return true;

		for (int j=0; j<size; j++)
			if (board[x][j] == 'Q')
				return true;

		for (int i=x, j=y; i>=0 && j>=0; i--, j--)
			if (board[i][j] == 'Q')
				return true;

		for (int i=x, j=y; i<size && j<size; i++, j++)
			if (board[i][j] == 'Q')
				return true;
		
		for (int i=x, j=y; i>=0 && j<size; i--, j++)
			if (board[i][j] == 'Q')
				return true;

		for (int i=x, j=y; i<size && j>=0; i++, j--)
			if (board[i][j] == 'Q')
				return true;

		return false;
	}
};
