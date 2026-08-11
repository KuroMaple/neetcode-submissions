class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> memo(amount + 1, -1);
        auto dfs = [&](this auto dfs, int currentAmount) -> int {
            if(currentAmount == 0) return 0;
            if(memo[currentAmount] != -1) return memo[currentAmount];


            int minWays = amount + 1;
            for(const auto& coin : coins) {
                if(currentAmount  >= coin) {
                    minWays = std::min(minWays, dfs(currentAmount - coin) + 1);
                }
            }

            memo[currentAmount] = minWays;
            return minWays;
        };  
        
        int result = dfs(amount);
        
        return result == amount + 1 ? -1 : result;
    }
};
