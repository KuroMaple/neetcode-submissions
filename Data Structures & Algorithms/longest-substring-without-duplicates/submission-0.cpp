class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<int> MySet;
        int longestSubstring = 0;

        if(s.length() == 0) return longestSubstring;
        int l = 0; // just used to track the length
        for(int r = 0; r < s.length(); ++r){
            while(MySet.find(s[r]) != MySet.end()){
                MySet.erase(s[l]);
                ++l;
            }

            MySet.insert(s[r]);
            longestSubstring = max(longestSubstring, r - l + 1);
        }

        return longestSubstring;
    }
};
