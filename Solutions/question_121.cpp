class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if (prices.size() <= 1)
			return 0;

		int minPrice = prices[0];
		int maxProfit = 0;
		
		for (int i=1; i<prices.size(); i++) {
			if (prices[i] - minPrice > maxProfit)
				maxProfit = prices[i] - minPrice;

			if (prices[i] < minPrice)
				minPrice = prices[i];
		}

		return maxProfit;
    }
};
