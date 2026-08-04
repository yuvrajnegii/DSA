class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxp = 0;

        while(right < prices.size()) {
            int profit = prices[right] - prices[left];
            maxp = max(profit, maxp);

            if(prices[left] > prices[right])
                left = right;
            
            right++;
        }

        return maxp;
    }
};