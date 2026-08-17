class Solution {
    bool hasCycleDFS(int i, int parent, const std::unordered_map<int, std::vector<int>>& edgeMap, std::unordered_set<int>& visited) {
        visited.insert(i);

        auto it = edgeMap.find(i);
        if(it == edgeMap.end()) return false; // node has no edges

        for(const auto& nei: edgeMap.at(i)){
            if(!visited.contains(nei)) {
                if(hasCycleDFS(nei, i, edgeMap, visited)) {
                    return true;
                }
            }
            else if(nei != parent) {
                return true;
            }
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        std::unordered_map<int, std::vector<int>> edgeMap;
        std::unordered_set<int> visited;
        for(const auto& edge: edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }

        if(hasCycleDFS(0, -1, edgeMap, visited)) {
            return false;
        }
        return visited.size() == n;
    }
};
