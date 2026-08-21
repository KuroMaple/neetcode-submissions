class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<std::vector<int>> memo(nums.size(), std::vector<int>(nums.size() + 1, -1));
        return dfs(0, -1, nums, memo);
    }

    int dfs(int i, int prevIndex, vector<int>& nums, std::vector<std::vector<int>>& memo) {
        if(i == nums.size()) return 0;
        if(memo[i][prevIndex + 1] != -1) return memo[i][prevIndex + 1];

        int LIS = dfs(i + 1, prevIndex, nums, memo);

        if(prevIndex == -1 || nums[prevIndex] < nums[i]) {
            LIS = std::max(LIS, 1 + dfs(i + 1, i, nums, memo));
        }

        memo[i][prevIndex + 1] = LIS;

        return LIS;
    }
};
