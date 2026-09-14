class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            while(l < r  && !std::isalnum(s[l])) {
                ++l;
            }

            while(r > l && !std::isalnum(s[r])) {
                --r;
            }
            if(std::tolower(s[l]) == std::tolower(s[r])) {
                ++l;
                --r;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
