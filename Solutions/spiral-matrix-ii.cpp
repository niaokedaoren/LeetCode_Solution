class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > board(n, vector<int>(n));
		int layerNum = (n+1) / 2;
		int val = 1;
		for (int layer=0; layer<layerNum; layer++) {
			for (int j=layer; j<n-layer; j++)
				board[layer][j] = val++;

			for (int i=layer+1; i<n-layer; i++)
				board[i][n-1-layer] = val++;

			for (int j=n-2-layer; j>=layer; j--)
				board[n-layer-1][j] = val++;

			for (int i=n-layer-2; i>layer; i--)
				board[i][layer] = val++;
		}

		return board;
    }
};
