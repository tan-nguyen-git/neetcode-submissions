class Solution {
public:
    //10 5 1 4 2 7
    int maxProfit(vector<int>& prices) {
        
        int sz = prices.size();
        int res = 0; //start as 0 because 0 mean not buying/selling
        int minLeft = prices[0];
        for(int i = 0 ; i< sz ; i++){
            int profit = prices[i] - minLeft;
            res = max(profit, res);
            minLeft = min(minLeft, prices[i]);
        }
        return res;
        
        
    }
};
