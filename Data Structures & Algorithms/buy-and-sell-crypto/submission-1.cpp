class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentProfit = 0;
        int l = 0;
        
        for(int r = 0; r < prices.size(); ++r) {
            while(prices[l] > prices[r]){
                ++l;
            }

            currentProfit = max(currentProfit, prices[r] - prices[l]);
        }


        return currentProfit;
    }
};
