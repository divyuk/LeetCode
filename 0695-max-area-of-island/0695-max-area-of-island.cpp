class Solution {
public:
    bool valid(int i , int j , int r, int c ,vector<vector<int>>& grid ){
        if(i>=0 and i < r and j>=0 and j<c and grid[i][j] == 1)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid , int r, int c, int i , int j , int &count){
        grid[i][j] = 0;
        count++;
        if(valid(i-1,j,r,c,grid))
            dfs(grid , r,c,i-1,j,count);
        if(valid(i+1,j,r,c,grid))
            dfs(grid , r,c,i+1,j,count);
        if(valid(i,j-1,r,c,grid))
            dfs(grid , r,c,i,j-1,count);
        if(valid(i,j+1,r,c,grid))
            dfs(grid , r,c,i,j+1,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0 ;
        int ans = 0 ;
        
        for(int i = 0 ; i < r ; i++){
            for(int  j = 0  ; j < c ;j++){
                if(grid[i][j] == 1){
                    cout<<c<<"\n";
                    dfs(grid,r,c,i,j,count);
                    ans = max(ans , count);
                    count = 0;
                }
            }
        }
        return ans;
    }
};