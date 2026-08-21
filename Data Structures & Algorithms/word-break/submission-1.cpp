class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        std::vector<std::vector<int>> memo(s.size(), std::vector<int>(s.size(), -1));

        return dfs(0, 0, s, wordSet, memo);
    }

    bool dfs(int startIndex, int currIndex, std::string& s, std::unordered_set<std::string>& wordSet, std::vector<std::vector<int>>& memo) {
        if(startIndex == s.size()) return true;
        if(currIndex == s.size()) return false;

        if(memo[startIndex][currIndex] != -1) return memo[startIndex][currIndex];

        std::string currentWord = s.substr(startIndex, currIndex - startIndex + 1);
        bool breakable = false;
        if(wordSet.contains(currentWord)) {
            breakable = dfs(currIndex + 1, currIndex + 1, s, wordSet, memo);
        }

        memo[startIndex][currIndex] = breakable || dfs(startIndex, currIndex + 1, s, wordSet, memo);
        return memo[startIndex][currIndex];
    }
};
