class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> memo(n, -1);
        auto dfs = [&](this auto self, int i) -> int {
            if(i == n) {
                return 1;
            }
            if (i > n) return 0;
            if(memo[i] != -1) return memo[i];
            auto result = self(i + 1) + self(i + 2);
            memo[i] = result;
            return memo[i];
        };

        return dfs(0);
    }
};
