class Solution {
public:
    bool dfs(int r, int c,vector<vector<int>>& maze, vector<int> curr,vector<int>& destination,vector<vector<bool>>&visited  ){
        
        if(visited[curr[0]][curr[1]] ) return false;// ball is trapped around the maze
        
        if(curr[0] == destination[0] and curr[1] == destination[1]) return true;
        
        visited[curr[0]][curr[1]] = true;
        vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        
        for(pair<int,int>dir : directions){
            int x = curr[0] , y = curr[1];
            int move_x = dir.first, move_y = dir.second;
            // Move the ball in the chosem directions untill it cant move
            while(x>=0 and x<r and y>=0 and y<c and maze[x][y] == 0){
                 x = x + move_x;
                 y = y + move_y;
            }
            // Once this breaks it means we are inside the ball hence reverting back
            // and starting from the last position
            x -=move_x;
            y -=move_y;
            if(dfs(r,c,maze,{x,y}, destination, visited))return true;
        }
        return false;
    }
    
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start,vector<int>& destination) {
        int r = maze.size();
        int c = maze[0].size();
        vector<vector<bool>>visited(r, vector<bool>(c,false));
        return dfs(r,c,maze,start,destination,visited);
    }
};
// TC : O(m.n (m+n))