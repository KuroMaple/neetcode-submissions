class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> seenMap;

        for(int i = 0; i < nums.size(); ++i) {
            int goal = target - nums[i];
            if(seenMap.contains(goal)){
                return {seenMap[goal], i};
            }

            seenMap[nums[i]] = i;
        }
    }
};
