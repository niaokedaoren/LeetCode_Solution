class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > collection;

		if (numRows <= 0)
			return collection;

		vector<int> row(1, 1);
		collection.push_back(row);
		for (int i=1; i<numRows; i++) {
			row.push_back(1);
			for (int n = row.size()-2; n>0; n--)
				row[n] += row[n-1];

			collection.push_back(row);
		}

		return collection;
    }
};
