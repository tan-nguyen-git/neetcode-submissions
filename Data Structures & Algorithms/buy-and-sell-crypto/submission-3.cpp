class Solution {
public:
    //10 5 1 4 2 7
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currMax = 0;
        int minBuy =prices[0];
        for(int i =0, j = 1; i < n-1 ;i++, j++){
            minBuy = min(minBuy, prices[i]);
            int profit= prices[j] - minBuy;

            currMax = max(profit, currMax);
        }
        return currMax >0 ? currMax : 0;
        
        
    }
};
