class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for(int a = 1; a <= amount; ++a) {
            for(const auto& coin : coins) {
                if(a - coin >= 0) {
                    dp[a] = std::min(dp[a], 1 + dp[a - coin]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
