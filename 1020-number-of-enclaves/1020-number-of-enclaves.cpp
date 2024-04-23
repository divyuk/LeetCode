class Solution {
    void dfs(vector<vector<int>>& land, int r, int c, int i, int j ){
        land[i][j] = 2;
        vector<pair<int,int>>dir = {{1,0} , {-1,0} , {0,1} , {0,-1} }; 
        for(pair<int,int>d : dir){
            int x = i + d.first;
            int y = j + d.second;
            if(x>=0 and x<r and y>=0 and y<c and land[x][y] == 1 )
                dfs(land, r, c , x , y);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        vector< vector<int> > land(grid.begin() , grid.end() );
        
        // T ---> B
        for(int i = 0 ; i<r; i++  ){
            if(land[i][0] == 1)
                dfs(land,r,c,i,0);
            if(land[i][c-1]  == 1)
                dfs(land,r,c,i,c-1);
        }
        
        
        // L ---> R
        for(int j = 0 ; j<c; j++  ){
            if(land[0][j] == 1)
                dfs(land,r,c,0,j);
            if(land[r-1][j]  == 1)
                dfs(land,r,c,r-1,j);
        }
        
        for(int i = 0 ;i< r; i++){
            for(int j = 0 ;j<c; j++){
                if(land[i][j] == 1) count++;
            }
        }
        return count;
    }
};