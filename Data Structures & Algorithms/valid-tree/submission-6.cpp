class Solution {
    bool hasCycleDFS(int i, int parent, std::unordered_map<int, std::vector<int>>& adjList, std::unordered_set<int>& visited) {
        if(visited.contains(i)) return false;

        visited.insert(i);
        for(const auto& nei : adjList[i]) {
            if(visited.contains(nei) && nei != parent) return true;
            
            if(hasCycleDFS(nei, i, adjList, visited)){
                return true;
            }
        }

        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> adjList;
        std::unordered_set<int> visited;
        for(const auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        if(hasCycleDFS(0, -1, adjList, visited)) {
            return false;
        }

        return visited.size() == n;
    }
};
