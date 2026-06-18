class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forwardProducts(nums.size());
        vector<int> backwardProducts(nums.size());

        int currentProduct = 1;
        for(int i = 0; i < nums.size(); ++i) {
            forwardProducts[i] = currentProduct;
            currentProduct *= nums[i];
        }
        
        currentProduct = 1;
        for(int j = nums.size() - 1; j >= 0; --j) {
            backwardProducts[j] = currentProduct;
            currentProduct *= nums[j];
        }

        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            result[i] = forwardProducts[i] * backwardProducts[i];
        }

        return result;
        // 1 1 2 8
        // 48  24 6  1
    }
};
