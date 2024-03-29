class Solution {
public:
    
    bool valid(vector<vector<char>>& grid, int i,int j, int r, int c){
        if(i>=0 and i<r and j>=0 and j<c and grid[i][j]=='1')
            return true;
        return false;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int r,int c){
        grid[i][j]='0';
        vector<pair<int, int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};
        
        for(pair<int, int> &dir:  directions){
            int newR = i+dir.first;
            int newC = j + dir.second;
            if(valid(grid, newR , newC,r,c))
                dfs(grid, newR, newC , r,c);
        }
       //  if(valid(grid,i+1,j,r,c))
       //      dfs(grid,i+1,j,r,c);
       // if(valid(grid,i-1,j,r,c))
       //      dfs(grid,i-1,j,r,c);
       // if(valid(grid,i,j+1,r,c))
       //      dfs(grid,i,j+1,r,c);
       // if(valid(grid,i,j-1,r,c))
       //      dfs(grid,i,j-1,r,c);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count=0;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,r,c);
                    count++;
                }
            }
        }
        return count;
    }
};