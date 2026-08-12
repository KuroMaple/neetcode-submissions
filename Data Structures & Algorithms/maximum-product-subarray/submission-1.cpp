class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = 1;
        int currentMin = 1;
        int result = nums[0];
        for(int i = 0; i < nums.size(); ++i) {
            auto oldCurrentMax = currentMax;
            currentMax = std::max({currentMin * nums[i], oldCurrentMax * nums[i], nums[i]});
            currentMin = std::min({currentMin * nums[i], oldCurrentMax * nums[i], nums[i]});
            
            result = std::max(currentMax, result);
        }

        return result;
    }
};
