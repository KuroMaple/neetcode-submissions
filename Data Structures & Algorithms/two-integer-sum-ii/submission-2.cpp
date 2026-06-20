class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> differenceToIndex;

        for(int i = 0; i < numbers.size(); ++i)
        {
            auto difference = target - numbers[i];
            if(differenceToIndex.contains(difference)){
                return { differenceToIndex[difference] + 1 , i + 1 };
            }
            differenceToIndex[numbers[i]] = i;
        }

        return {};
    }
};
