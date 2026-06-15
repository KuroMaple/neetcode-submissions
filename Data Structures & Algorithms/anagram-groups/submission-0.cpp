class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,vector<string>> resultMap;

        for(string s: strs){
            int keyArr[26] = {0};
            for(char c: s){
                keyArr[c - 'a']++;
            }

            stringstream ss;
            int size = sizeof(keyArr) / sizeof(keyArr[0]);

            
            for(int i = 0; i < size; ++i) {
               ss << keyArr[i];
               if(i < size - 1){
                ss << ',';
               }
            }

            string key = ss.str();

            resultMap[key].push_back(s);
        } 
        
        vector<vector<string>> resultVector;
        for(auto [key, val]: resultMap){
            resultVector.push_back(val);
        }
        return resultVector;

    }
};
