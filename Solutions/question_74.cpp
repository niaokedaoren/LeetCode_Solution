class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (matrix.size() == 0)
			return false;

		int raws = matrix.size();
		int cols = matrix[0].size();

		int left = 0;
		int right = raws * cols - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int x = mid / cols;
			int y = mid % cols;
			if (matrix[x][y] < target)
				left = mid + 1;
			else if (matrix[x][y] > target)
				right = mid - 1;
			else
				return true;
		}

		return false;
    }
};
