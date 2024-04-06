class Solution {
public:
    int checkIfGridIsAllZeros(vector<vector<int>>& grid){
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) count += grid[i][j];
                else return 0;
            }
        }
        return count;
    }
    
    bool isValid(vector<vector<int>>& grid, int i,int j, int r, int c){
        return i>=0 and i<r and j>=0 and j < c and grid[i][j]!=0;
    }
    void checkPaths(vector<vector<int>>& grid, int x, int y, int r,int c,int currentGold, int &maxGold){

        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
        if(isValid(grid, x,y,r,c)){
            int store=grid[x][y];
            currentGold+=store;
            grid[x][y]=0;
            for(pair<int,int>dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second; 
                checkPaths(grid,newX,newY,r,c,currentGold,maxGold);
            }
            
            maxGold = max(maxGold, currentGold);
            currentGold-=store;
            grid[x][y] = store;
        }
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int count = checkIfGridIsAllZeros(grid);
        if(count != 0) return count; 
        int r = grid.size();
        int c =grid[0].size();
        int maxGold = 0;
        for(int i = 0; i< r; i++){
            for(int j =0 ; j< c; j++){
                int currentGold=0;
                
                if(grid[i][j] !=0 )
                    checkPaths(grid, i, j, r,c,currentGold, maxGold);
            }
        }
        
        return  maxGold;
    }
};