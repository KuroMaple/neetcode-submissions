class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> numSet;

        for(const auto& num : nums)
        {
            if(numSet.contains(num)) return true;

            numSet.insert(num);
        }

        return false;
    }
};