class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		const int size = 9;

		//check each row
		for (int i=0; i<size; i++) {
			vector<bool> exist(size);
			for (int j=0; j<size; j++) {
				if (board[i][j] != '.') {
					int id = board[i][j] - '1';
					if (exist[id])
						return false;
					else
						exist[id] = true;
				}
			}
		}

		//check each column
		for (int j=0; j<size; j++) {
			vector<bool> exist(size);
			for (int i=0; i<size; i++) {
				if (board[i][j] != '.') {
					int id = board[i][j] - '1';
					if (exist[id])
						return false;
					else
						exist[id] = true;
				}
			}
		}

		//check each block
		for (int x=0; x<3; x++) {
			for (int y=0; y<3; y++) {
				vector<bool> exist(size);
				for (int i=x*3; i<(x+1)*3; i++) {
					for (int j=y*3; j<(y+1)*3; j++) {
						if (board[i][j] != '.') {
							int id = board[i][j] - '1';
							if (exist[id])
								return false;
							else
								exist[id] = true;
						}
					}
				}
			}
		}

		return true;
    }
};
