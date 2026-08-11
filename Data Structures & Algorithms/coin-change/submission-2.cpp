class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::queue<int> q;
        std::unordered_set<int> seenAmounts;
        q.push(0);
        seenAmounts.insert(0);
        int coinCount = 0;
        while(!q.empty()) {
            int currentLevelSize = q.size();
            while(currentLevelSize--){
                int currentAmount = q.front();
                q.pop();
                if(currentAmount == amount) return coinCount;
                for(const auto& coin : coins) {
                    int newAmount = currentAmount + coin;
                    if(newAmount > amount) continue;
                    if(!seenAmounts.contains(newAmount)){
                        q.push(newAmount);
                        seenAmounts.insert(newAmount);
                    }
                }
            }
            coinCount++;
        }
        return -1;
    }
    
};
