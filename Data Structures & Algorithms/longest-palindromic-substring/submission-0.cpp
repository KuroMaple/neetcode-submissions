class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        int resultIndex = 0;
        int resultLength = 0;
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if(j - i + 1 > resultLength) {
                        resultLength = j - i + 1;
                        resultIndex = i;
                    }
                }
            }
        }

        return s.substr(resultIndex, resultLength);
    }
};
