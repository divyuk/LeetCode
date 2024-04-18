class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;
        vector<pair<int,int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};
        for(int i = 0; i< r; i++){
            for(int j =0; j< c; j++){
                if(grid[i][j] == 1){
                    
                    if(i==0) perimeter++;
                    if(i == r-1) perimeter++;
                    if(j==0) perimeter++;
                    if(j== c-1) perimeter++;
                    
                    for(pair<int,int>dir : directions){
                        int newX = i + dir.first;
                        int newY = j + dir.second;
                        if(newX>=0 and newX<r and newY>=0 and newY<c and grid[newX][newY]==0)
                            perimeter++;
                        // else if(i==0 and grid[i][j]==1) perimeter++;
                        // else if(newX<= 0 or newY<0 or newX>=r or newY>=c)
                        //     perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};