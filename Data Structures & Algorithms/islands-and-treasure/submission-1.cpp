class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS_COUNT = grid.size();
        int COLS_COUNT = grid[0].size();
        std::array<std::array<int,2>,4> directions = {{
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        }};
        std::vector<std::vector<bool>> visited(ROWS_COUNT, std::vector<bool>(COLS_COUNT, false));
        std::queue<std::tuple<int, int>> q;

        auto multiSourceBFS = [&]() -> void {
            

            while(!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                for(auto& dir: directions) {
                    int newI = i + dir[0];
                    int newJ = j + dir[1];

                    if(newI >= 0 && newI < ROWS_COUNT && 
                    newJ >= 0  && newJ < COLS_COUNT &&
                    !visited[newI][newJ] && grid[newI][newJ] != -1) {
                        grid[newI][newJ] = grid[i][j] + 1;
                        q.push({newI, newJ});
                        visited[newI][newJ] = true;
                    }
                }
            }
        };

        

        // Collect all treasure locations
        for(int i = 0; i < ROWS_COUNT; ++i) {
            for(int j = 0; j < COLS_COUNT; ++j) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        // Propogate outwards from each treasure
        multiSourceBFS();
    }
};
