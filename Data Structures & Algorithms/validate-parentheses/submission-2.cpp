class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        static const unordered_map<char, char> closeToOpenBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        // Odd length strings can never be valid
        if(s.size() % 2) return false;

        for(char currentBracket : s){
            auto foundBracket = closeToOpenBrackets.find(currentBracket);
            if(!bracketStack.empty() && foundBracket != closeToOpenBrackets.end()){
                if(bracketStack.top() == foundBracket->second) {
                    bracketStack.pop();
                }
                else {
                    return false;
                }
            }
            else{
                bracketStack.push(currentBracket);
            }
        }

        return bracketStack.empty();
    }
};
