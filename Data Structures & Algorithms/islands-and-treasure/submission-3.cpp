class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return;

        int ROWS_COUNT = grid.size();
        int COLS_COUNT = grid[0].size();
        std::array<std::array<int,2>,4> directions = {{
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        }};
        std::queue<std::pair<int, int>> q;

        auto multiSourceBFS = [&]() -> void {
            

            while(!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                for(const auto& [dr, dc]: directions) {
                    int newI = i + dr;
                    int newJ = j + dc;

                    if(newI >= 0 && newI < ROWS_COUNT && 
                    newJ >= 0  && newJ < COLS_COUNT &&
                    grid[newI][newJ] == INT_MAX) {
                        grid[newI][newJ] = grid[i][j] + 1;
                        q.push({newI, newJ});
                    }
                }
            }
        };

        

        // Collect all treasure locations
        for(int i = 0; i < ROWS_COUNT; ++i) {
            for(int j = 0; j < COLS_COUNT; ++j) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // Propogate outwards from each treasure
        multiSourceBFS();
    }
};
