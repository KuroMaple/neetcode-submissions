class Solution {
    void dfs(int i, int n, std::unordered_map<int, std::vector<int>>& adjList, std::unordered_set<int>& visited) {
        if(i == n || visited.contains(i)) {
            return;
        }

        visited.insert(i);
        for(const auto& nei: adjList[i]) {
            dfs(nei, n, adjList, visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> adjList;
        int componentCount = 0;
        std::unordered_set<int> visited;
        for(const auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; ++i) {
            if(!visited.contains(i)) {
                ++componentCount;
                dfs(i, n, adjList, visited);
            }
        }

        return componentCount;
    }
};
