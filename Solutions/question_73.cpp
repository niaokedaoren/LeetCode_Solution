class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (matrix.size() == 0)
			return;

		int rows = matrix.size();
		int cols = matrix[0].size();

		bool curLine = false;
		bool nextLine = hasZero(matrix, 0);

		for (int i=0; i<rows-1; i++) {
			curLine = nextLine;
			nextLine = hasZero(matrix, i+1);
			for (int j=0; j<cols; j++) {
				if (matrix[i][j] == 0)
					matrix[i+1][j] = 0;
				else {
					if (curLine)
						matrix[i][j] = 0;
				}
			}
		}

		curLine = nextLine;
		for (int j=0; j<cols; j++) {
			if (matrix[rows-1][j] == 0) {
				for (int i=0; i<rows; i++)
					matrix[i][j] = 0;
			} else {
				if (curLine)
					matrix[rows-1][j] = 0;
			}
		}
    }

private:
	bool hasZero(const vector<vector<int> > &matrix, int row) {
		for (auto itr = matrix[row].cbegin(); 
				itr != matrix[row].cend(); itr++) {

			if (*itr == 0)
				return true;
		}

		return false;
	}
};
