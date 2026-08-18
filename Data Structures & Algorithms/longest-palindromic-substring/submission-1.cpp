class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        int resIdx = 0;
        int resLength = 0;

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j < n; ++j) {
                if(s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if((j - i + 1) > resLength) {
                        resLength = j - i + 1;
                        resIdx = i;
                    }
                }   
            }
        }

        return s.substr(resIdx, resLength);
        
    }
};
