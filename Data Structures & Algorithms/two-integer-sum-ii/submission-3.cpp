class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0;
        int rightPointer = numbers.size() - 1;

        while(leftPointer < rightPointer)
        {
            auto currentSum = numbers[leftPointer] + numbers[rightPointer];
            if(currentSum < target)
            {
                ++leftPointer;
            } 
            else if(currentSum > target)
            {
                --rightPointer;
            }
            else
            {
                return {leftPointer + 1, rightPointer + 1};
            }
        }

        return {};
    }
};
