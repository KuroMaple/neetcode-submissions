class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> MySet;
        for(int i = 0; i < nums.size(); ++i){
            if(MySet.contains(nums[i])){
                return true;
            }
            MySet.insert(nums[i]);
        }
        return false;
    }
};