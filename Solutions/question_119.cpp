class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<int> row;

		if (rowIndex < 0)
			return row;

		row.push_back(1);
		for (int i=0; i<rowIndex; i++) {
			row.push_back(1);
			for (int n=row.size()-2; n>0; n--) {
				row[n] += row[n-1];
			}
		}

		return row;
        
    }
};
