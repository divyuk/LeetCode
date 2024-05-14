class Solution {
private:
    int res=0;
    vector<pair<int,int>>dir{{0,1}, {0,-1}, {1,0} , {-1,0}};
    void backTrack(vector<vector<int>>& grid,int i, int j, int m, int n , int nonObstackle, int count ){
        
        if(i>=m or i<0 or j>=n or j<0 or grid[i][j]==-1) return;
        if(grid[i][j] == 2){
            if(count == nonObstackle) res++;
            return;
        }
        grid[i][j] = -1; // marking visited

        for(pair<int,int>&d : dir){
            int newX = i+d.first;
            int newY = j+d.second;
            backTrack(grid,newX,newY, m,n,nonObstackle,count+1 );
        }
        grid[i][j] = 0;
    
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Count non-obstackle paths
        int nonObstackle =0;
        int startX=0,startY=0;
        for(int i =0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) nonObstackle++;
                if(grid[i][j] == 1) startX=i,startY=j;
            }
        }
        nonObstackle++; // adding the start point also as its nonObstackle
        backTrack(grid,startX,startY,m,n,nonObstackle,0);
        return res;
    }
};