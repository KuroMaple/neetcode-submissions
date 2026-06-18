class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int foundIndex = -1;

        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        while(leftPointer <= rightPointer) 
        {
            int midPointer = (leftPointer + rightPointer) / 2;
            if(nums[midPointer] == target)
            {
                foundIndex = midPointer;
                break;
            }
            
            // left half sorted
            if(nums[leftPointer] <= nums[midPointer]) 
            {
                if(nums[leftPointer] <= target && nums[midPointer] > target)
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
                // right half sorted
                if(nums[midPointer] < target && nums[rightPointer] >= target) 
                {
                    leftPointer = midPointer + 1;
                }
                else 
                {
                    rightPointer = midPointer - 1;
                }
            }
        } // 3 5 6 0 1 2 target = 1

        return foundIndex;
    }
};
