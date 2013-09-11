class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (prices.size() <= 1)
			return 0;

		vector<int> profits(prices.size());

		for (int i=1; i<prices.size(); i++) {
			profits[i] = profits[i-1];
			
			if (prices[i] <= prices[i-1])
				continue;

			for (int j=i-1; j>=0; j--) {
				if (prices[i] > prices[j]) {
					int lastProfit = prices[i] - prices[j];
					if (lastProfit + profits[j] > profits[i])
						profits[i] = lastProfit + profits[j];
				}
			}
		}

		return profits.back();
    }
};
