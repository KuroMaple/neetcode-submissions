class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        std::array<std::array<int, 2>, 4> directions {{
            {0, 1},
            {0, -1},
            {-1, 0},
            {1, 0}
        }};
        int islandCount = 0;

        for(int i = 0; i < ROWS; ++i) {
            for(int j = 0; j < COLS; ++j) {
                if(grid[i][j] == '1') {
                    bfs(i, j, grid, directions, ROWS, COLS);
                    ++islandCount;
                }
            }
        }

        return islandCount;
    }

    void bfs(int i, int j, vector<vector<char>>& grid, const std::array<std::array<int, 2>, 4>& directions, const int ROWS, const int COLS) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(const auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if(newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY] == '1') {
                    q.push({newX, newY});
                    grid[newX][newY] = '0';
                }
            }
        }
    }

};
