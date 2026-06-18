class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count freq
        unordered_map<int,int> freqMap;

        for(int i = 0; i < nums.size(); ++i) {
            ++freqMap[nums[i]];
        }

        vector< vector<int> > buckets(nums.size() + 1);

        for(auto [val, freq] : freqMap) {
            buckets[freq].push_back(val);
        }

        vector<int> result;
        result.reserve(k); 
        int bucketPointer = nums.size(); // last element of buckets

        while(result.size() != k) {
            while(buckets[bucketPointer].empty()) {
                --bucketPointer;
            }

            result.insert(result.end(), buckets[bucketPointer].begin(), buckets[bucketPointer].end());
            --bucketPointer;
        }

        return result;
    }
};
