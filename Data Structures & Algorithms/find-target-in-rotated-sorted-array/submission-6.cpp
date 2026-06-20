class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1; 
        int targetIndex =  -1;

        while(leftPointer <= rightPointer)
        {
            int midPointer = (leftPointer + rightPointer) / 2;
            if(nums[midPointer] == target)
            {
                targetIndex = midPointer;
                break;
            }
            if(nums[leftPointer] <= nums[midPointer])
            {
                if(nums[leftPointer] <= target && target < nums[midPointer])
                {
                    rightPointer = midPointer - 1;
                }
                else
                {
                    leftPointer = midPointer + 1;
                }
            }
            else
            {
                if(nums[midPointer] < target && target <= nums[rightPointer])
                {
                    
                    leftPointer = midPointer + 1;
                }
                else
                {
                    rightPointer = midPointer - 1;
                }
            }
        }

        return targetIndex;
    }
};
