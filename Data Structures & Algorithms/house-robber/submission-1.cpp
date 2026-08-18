class Solution {
public:
    int rob(vector<int>& nums) {
        // i = max(i + i - 2, i - 1)
        int n = nums.size();
        if(n == 1) return nums[0];
        std::vector<int> dp(n, -1);

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for(int i = 2; i < n; ++i) {
            dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return std::max(dp[n - 1], dp[n - 2]);
    }
};
