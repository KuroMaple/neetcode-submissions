class Solution {
    std::unordered_map<int, int> memo;
    int dfs(std::vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int res = INT_MAX;

        for(const auto& coin : coins) {
            if(amount - coin >= 0) {
                int result = dfs(coins, amount - coin);
                if(result != INT_MAX) {
                    res = std::min(res, 1 + result);
                }
            }
        }

        memo[amount] = res;
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = dfs(coins, amount);
        return result == INT_MAX ? -1 : result; 
    }
};
