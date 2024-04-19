class Solution {
    int dp[100][100][201];
    bool check(vector<vector<char>>& grid, int i , int j, int r , int c, int bal , bool &ans){
        if( i == r || j == c ) return false;
        
        if(grid[i][j] == '(') bal++;
        else if(grid[i][j] == ')') bal--;
        if(bal<0) return false;
        
        if(dp[i][j][bal] !=-1) return dp[i][j][bal];
        
        if(i == r-1 and j == c-1 and bal==0) ans= true;
        
        bool down = check(grid,i+1,j,r,c,bal,ans);
        bool right = check(grid,i, j+1, r,c,bal,ans);
        
        return dp[i][j][bal] = down || right;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        bool ans = false;
        int r = grid.size();
        int c = grid[0].size();
        memset(dp, -1, sizeof(dp));
        check(grid, 0,0,r,c , 0 , ans); // grid, i,j,r,c,bal
        return ans;
    }
};