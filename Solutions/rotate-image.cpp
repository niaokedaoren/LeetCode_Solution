class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int size = matrix.size();
		int layerNum = (size - 1) / 2;
		
		for (int layer = 0; layer <= layerNum; layer++) {
			for (int n = layer; n<size-layer-1; n++) {
				int temp = matrix[layer][n];
				matrix[layer][n] = matrix[size-n-1][layer];
				matrix[size-n-1][layer] = matrix[size-layer-1][size-n-1];
				matrix[size-layer-1][size-n-1] = matrix[n][size-layer-1];
				matrix[n][size-layer-1] = temp;
			}
		}
    }
};
