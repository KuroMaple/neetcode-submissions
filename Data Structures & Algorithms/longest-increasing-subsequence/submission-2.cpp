class Solution {
    int dfs(const std::vector<int>& nums, std::vector<std::vector<int>>& memo, int i, int j) {
        if(i == nums.size()) return 0;
        if(memo[i][j + 1] != -1) return memo[i][j + 1];

        int subSeqLength = 0;
        if(j == -1 || nums[j] < nums[i]) {
            subSeqLength = 1 + dfs(nums, memo, i + 1, i);
        }
        memo[i][j + 1] = std::max(
            dfs(nums, memo, i + 1, j),
            subSeqLength
        );
        return memo[i][j + 1];
    }   
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<std::vector<int>> memo(nums.size(), std::vector<int>(nums.size() + 1, -1));
        return dfs(nums, memo, 0, -1);
    }
};
