class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        std::queue<int> q;
        std::unordered_set<int> visitedAmounts;
        std::vector<bool> seen(amount + 1, false);

        q.push(0);
        visitedAmounts.insert(0);
        seen[0] = true;
        int coinCount = 0;
        while(!q.empty()) {
            ++coinCount;
            int levelSize = q.size();
            while(levelSize--){
                int currentAmount = q.front();
                q.pop();
                for(const auto& coin : coins) {
                    int nextAmount = coin + currentAmount;
                    if(nextAmount == amount) {
                        return coinCount;
                    }
                    if(nextAmount < amount && !seen[nextAmount]) {
                        q.push(nextAmount);
                        seen[nextAmount] = true;
                    }
                }
            }
            
        }

        return -1;
    }
};
