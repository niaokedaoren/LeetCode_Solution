class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (prices.size() <= 1)
			return 0;

		vector<int> firstProfits(prices.size());
		int minPrice = prices[0];
		for (int i=1; i<prices.size(); i++) {
			if (prices[i] - minPrice > firstProfits[i-1])
				firstProfits[i] = prices[i] - minPrice;
			else
				firstProfits[i] = firstProfits[i-1];

			if (prices[i] < minPrice)
				minPrice = prices[i];
		}

		int max = firstProfits.back();
		int maxPrice = prices.back();
		int secondProfit = 0;
		for (int i=prices.size()-1; i>=0; i--) {
			if (maxPrice - prices[i] > secondProfit)
				secondProfit = maxPrice - prices[i];

			if (firstProfits[i] + secondProfit > max)
				max = firstProfits[i] + secondProfit;

			if (prices[i] > maxPrice)
				maxPrice = prices[i];
		}

		return max;
    }
};
