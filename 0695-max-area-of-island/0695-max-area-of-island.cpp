class Solution {
private:
    bool valid(int i, int j, vector<vector<int>>& grid, int r , int c){
        return (i>=0 and i<r and j>=0 and j<c and grid[i][j] == 1);
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int r , int c, int &count){
        grid[i][j] = 0;
        count++;
        vector<pair<int,int>>directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};
        
        for(pair<int,int> dir : directions){
            int newR = i + dir.first;
            int newC = j + dir.second;
            if(valid(newR , newC , grid, r,c)){
                dfs(newR , newC , grid, r,c,count);
            }
        }
    }
    
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxArea = 0;int count =0;
        for(int i = 0 ; i< r; i++){
            for(int j =0 ; j< c; j++){
                if(grid[i][j] == 1){
                    dfs(i,j, grid,r,c,count);
                    maxArea = max(maxArea, count);
                    count=0;
                }
            }
        }
        return maxArea;
    }
};