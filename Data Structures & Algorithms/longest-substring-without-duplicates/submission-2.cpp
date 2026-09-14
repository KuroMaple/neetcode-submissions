class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> letterSet;
        int result = 0;
        int l = 0;
        for(int r = 0; r < s.size(); ++r) {
            while(l < r && letterSet.contains(s[r])){
                letterSet.erase(s[l]);
                ++l;
            }
            letterSet.insert(s[r]);
            result = std::max(result, r - l + 1);
        }
        return result;
    }
};
