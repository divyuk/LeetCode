class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int r = rooms.size();
        int c = rooms[0].size();
        queue<pair<int,int> >q; // gates queue
        for(int i = 0; i< r; i++){
            for(int j = 0 ; j< c; j++){
                if(rooms[i][j] == 0)
                    q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int size = q.size();
    
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<pair<int,int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};
            for(pair<int,int> dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;
                if(newX >=0 and newX < r and newY >= 0 and newY< c and rooms[newX][newY] ==2147483647){
                     rooms[newX][newY] = rooms[x][y] +1;
                    q.push({newX, newY});

            }
        }
        }
    }
};