class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        std::vector<int> dp(n, -1);
        auto dfs = [&](this auto dfs, int i) -> int {
            if(i == n) return 1;
            if(i > n || s[i] == '0') return 0;
            if(dp[i] != -1) return dp[i];


            int bonus = 0;
            if(i <= n - 2) {
                int twoDigits = std::stoi(s.substr(i, 2));
                if(twoDigits >= 10 && twoDigits <= 26) {
                    bonus = dfs(i + 2);
                }
            }
            dp[i] = dfs(i + 1) + bonus;
            return dp[i];
            
        };

        return dfs(0);
    }
};
