class Solution {
public:
    int findMin(vector<int> &nums) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        int result = nums[leftPointer];
        // 6 1 2  3
        // 4 5 1 2 3
        // 1 2 3
        // 4 1 2 3
        while(leftPointer <= rightPointer){
            //Check if entire subarray is sorted
            if(nums[leftPointer] < nums[rightPointer]){
                result = min(result, nums[leftPointer]);
                break;
            }
            
            int middlePointer = (leftPointer + rightPointer) / 2;
            result = min(result, nums[middlePointer]);

            if(nums[leftPointer] <= nums[middlePointer]) {
                leftPointer = middlePointer + 1;
            }
            else {
                rightPointer = middlePointer - 1;
            }
        }

        return result;
    }
};
