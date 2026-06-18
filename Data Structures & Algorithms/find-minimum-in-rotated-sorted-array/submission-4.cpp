class Solution {
public:
    int findMin(vector<int> &nums) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        int result = nums[leftPointer];

        while(leftPointer <= rightPointer) {
            // check if array is sorted
            if(nums[leftPointer] < nums[rightPointer]) {
                result = min(result, nums[leftPointer]);
                break;
            }

            int midPointer = (leftPointer + rightPointer) / 2;
            result = min(result, nums[midPointer]);

            if(nums[leftPointer] <= nums[midPointer]) {
                leftPointer = midPointer + 1;
            }
            else {
                rightPointer = midPointer - 1;
            }
        }

        return result;
    }
};
/*
    [6,1,2] midPointer = 4
*/