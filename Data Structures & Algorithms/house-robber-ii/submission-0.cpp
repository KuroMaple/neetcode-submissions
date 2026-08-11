class Solution {
    int houseRobberDP(std::span<const int> numsSubset) {
        int n = numsSubset.size();
        if(n == 1) return numsSubset[0];
        std::vector<int> dp(n, -1);

        dp[0] = numsSubset[0];
        dp[1] = std::max(numsSubset[0], numsSubset[1]);
        for(int i = 2; i < numsSubset.size(); ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + numsSubset[i]);
        }
        return dp[n - 1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return std::max(
            houseRobberDP(std::span(&nums[0], n - 1)),
            houseRobberDP(std::span(&nums[1], n - 1))
        );
    }
};
