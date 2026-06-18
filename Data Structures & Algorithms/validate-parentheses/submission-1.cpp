class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        unordered_map<char, char> closeToOpenBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for(char currentBracket : s){
            if(!bracketStack.empty() && closeToOpenBrackets.contains(currentBracket)){
                if(bracketStack.top() == closeToOpenBrackets[currentBracket]) {
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
