class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int n : nums) {
            freqMap[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto [val, freq] : freqMap) {
            buckets[freq].push_back(val);
        }

        vector<int> result;
        result.reserve(k);
        for(int bucketPointer = nums.size(); bucketPointer >= 0; --bucketPointer) {
            if(buckets[bucketPointer].empty()){
                continue;
            }

            result.insert(
                result.end(), 
                make_move_iterator(buckets[bucketPointer].begin()),
                make_move_iterator(buckets[bucketPointer].end())
            );
            if(result.size() == k) {
                return result;
            }
        }
    }
};
