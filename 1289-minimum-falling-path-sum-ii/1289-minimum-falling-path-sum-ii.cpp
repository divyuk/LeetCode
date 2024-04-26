class Solution {
    
    int solve(int col , int row ,int n, vector<vector<int>>& grid, vector<vector<int>>&dp){
        
        if(row == n-1) return grid[row][col];
        
        if(dp[row][col] != -1) return dp[row][col];
        int ans = INT_MAX;
        for(int nextCol = 0; nextCol<n ; nextCol++ ){
            if(nextCol!=col)
                ans = min(ans, solve(nextCol, row+1, n , grid, dp) );
        }
        return dp[row][col] = grid[row][col] + ans;
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int col = 0 ; col < n ; col++){
            result = min(result , solve(col,0,n,grid, dp));
        }
        
        return result;
    }
};