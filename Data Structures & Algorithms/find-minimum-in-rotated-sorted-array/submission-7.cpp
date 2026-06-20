class Solution {
public:
    int findMin(vector<int> &nums) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        int currentMin = nums[leftPointer];

        while(leftPointer <= rightPointer)
        {
            int midPointer = (leftPointer + rightPointer) / 2;

            if(nums[leftPointer] < nums[rightPointer])
            {
                currentMin = min(currentMin, nums[leftPointer]);
                break;
            }

            currentMin = min(currentMin, nums[midPointer]);

            if(nums[leftPointer] <= nums[midPointer])
            {
                leftPointer = midPointer + 1;
            } 
            else 
            {
                rightPointer = midPointer - 1;
            }
        } 

        return currentMin;
    }
}; 
