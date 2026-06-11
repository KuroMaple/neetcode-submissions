class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        std::unordered_map<char, int> letterCount;
        for(int i = 0; i < s.length(); ++i){
            ++letterCount[s[i]];
            --letterCount[t[i]];
        }

        for(auto &c : letterCount){
            if(c.second != 0){
                return false;
            }
        }
        return true;
    }
};
