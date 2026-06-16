class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hash map to count freqs
        unordered_map<int, int> freqMap;
        for(int n: nums){
            freqMap[n]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto [val, freq] : freqMap){
            buckets[freq].push_back(val);
        }

        vector<int> result;
        result.reserve(k);
        int bucketPointer = nums.size();
        while(k != 0) {
            if(buckets[bucketPointer].empty()){
                bucketPointer--;
                continue;
            }


            k -= buckets[bucketPointer].size();
            // Move semantics
            result.insert(result.end(), 
            std::make_move_iterator(buckets[bucketPointer].begin()), 
            std::make_move_iterator(buckets[bucketPointer].end()));
            bucketPointer--;
        }

        return result;
        
    }
};
