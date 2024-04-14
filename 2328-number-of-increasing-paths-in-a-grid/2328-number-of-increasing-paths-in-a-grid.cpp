class Solution {
private:
    vector<vector<int>>dp;
    vector<pair<int,int>>directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};
    const long long MOD = 1e9+7;
    bool valid(vector<vector<int>>& grid, int i, int j, int r, int c){
        return (i>=0 and i<r and j>=0 and j<c);
    }
    int dfs(vector<vector<int>>& grid, int i, int j, int r, int c){
        int res = 1;
        if(dp[i][j] !=-1) return dp[i][j];
        for(auto dir : directions){
            int newX = i+dir.first;
            int newY = j+dir.second;
            if(valid(grid, newX, newY, r, c) and grid[newX][newY] < grid[i][j] ) 
                res= (res+dfs(grid, newX, newY, r, c))%MOD;
        }
        return dp[i][j] = res;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
       int r = grid.size();
       int c = grid[0].size();
       int paths = 0;
       dp.resize(r,vector<int>(c,-1));
       for(int i =0; i< r; i++){
           for(int j =0 ; j< c ; j++){
               paths = (paths+ dfs(grid, i , j, r, c))%MOD;
           }
       }
       return paths;
    }
};