class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>>q;
        int fresh =0;
        for(int i = 0; i< r ; i++){
            for(int j = 0; j< c; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh==0) return 0;
        
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            int t = 0;
            while(size--){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                vector<pair<int,int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};
                
                for(pair<int,int> dir : directions){
                    int newR = x + dir.first;
                    int newC  = y + dir.second;
                    if(newR >=0 and newR<r and newC>=0 and newC < c and grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        q.push({newR , newC});
                        t++;
                    }
                }
                
            }
            if(t) time++;    
        }
        for(int i = 0; i< r ; i++){
            for(int j = 0; j< c; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return time;
        
    }
};