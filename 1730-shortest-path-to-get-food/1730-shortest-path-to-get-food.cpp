class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e6;  // Max value for INF

        vector<vector<int>> mat(m, vector<int>(n, INF));

        queue<pair<int, int>> q;
        int x_ = 0, y_ = 0;

        // Initialize the queue with food cells
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '#') {
                    q.push({i, j});
                    mat[i][j] = 0;
                }
                if(grid[i][j] == '*'){
                    x_ = i;
                    y_ = j;
                }
            }
        }

        vector<pair<int, int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(const auto& dir : dirs){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] != 'X'){
                    if(mat[newX][newY] > mat[x][y] + 1) {
                        mat[newX][newY] = mat[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return mat[x_][y_] == INF ? -1 : mat[x_][y_];
    }
};
