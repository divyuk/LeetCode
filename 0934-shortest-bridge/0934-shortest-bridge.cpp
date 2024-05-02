class Solution {
private:
    vector<vector<int>> vis;
    queue<pair<int,int>> q;
    vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool valid(vector<vector<int>>& grid, int r, int c, int i, int j, int parity){
        return (i >= 0 and i < r and j >= 0 and j < c and grid[i][j] == parity);
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c, int i, int j){
        vis[i][j] = 1;
        q.push({i, j});
        for(pair<int,int>& d : dir){
            int x = i + d.first;
            int y = j + d.second;
            if(valid(grid, r, c, x, y, 1) and !vis[x][y] )
                dfs(grid, r, c, x, y);
        }
    }
    
    int bfs(vector<vector<int>>& grid, int r, int c){
        int steps = 0;
   
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(pair<int,int>& d : dir){
                    int x = i + d.first;
                    int y = j + d.second;
                    if(x>=0 and x<r and y>=0 and y< c and !vis[x][y] and grid[x][y] == 1)
                            return steps;
                    else if(valid(grid, r, c, x, y, 0) and !vis[x][y]){
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            steps++;
        }
        return -1; // if no solution found
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vis.resize(r, vector<int>(c,0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    dfs(grid, r, c, i, j);
                    return bfs(grid, r, c);
                }
            }
        }
        return -1; // if no island found
    }
};
