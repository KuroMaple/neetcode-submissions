class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        std::vector<std::vector<int>> memo(n, std::vector(n + 1, -1));
        auto dfs = [&](this auto dfs, int i, int j) -> int {
            if(i == n) return 0;
            if(memo[i][j + 1] != -1) return memo[i][j + 1];

            memo[i][j + 1] = dfs(i + 1, j);

            if(j == -1 || nums[j] < nums[i]) {
                memo[i][j + 1] = std::max(memo[i][j + 1], 1 + dfs(i + 1, i));
            }

            return memo[i][j + 1];
        };

        return dfs(0, -1);
    }
};
