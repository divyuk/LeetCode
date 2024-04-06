class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>>storeMin(r+1,vector<int>(c+1,0));
        for(int i =r-1 ; i>=0; i--){
            for(int j = c-1; j>=0; j--){
                
                if(i == r-1 and j == c-1) storeMin[i][j] = grid[i][j];
                else if (i== r-1) storeMin[i][j] = grid[i][j] + storeMin[i][j+1];
                else if( j== c-1 ) storeMin[i][j] = grid[i][j] + storeMin[i+1][j];
                else
                storeMin[i][j] = grid[i][j]  + min(storeMin[i][j+1] , storeMin[i+1][j]); 
            }
        }
        return storeMin[0][0];
    }
};