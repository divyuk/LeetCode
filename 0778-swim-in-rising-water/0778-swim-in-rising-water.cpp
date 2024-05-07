class Solution {
    typedef pair<int, pair<int,int>> P; // {height , i,j}
    vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<P,vector<P>, greater<>> pq; // min heap
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        pq.push({grid[0][0] ,{0,0}});
        
        while(!pq.empty()){
            P curr = pq.top();
            int h = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            if(i==n-1 and j == n-1) return h;
            pq.pop();
            for(pair<int,int>p : dir){
                int x = i + p.first;
                int y = j + p.second;
                if(x>=0 and x<n and y>=0 and y<n and !visited[x][y]){
                    pq.push( {max(grid[x][y], h) , {x,y} }  );
                    visited[x][y] = 1;
                }
            }
        }
        return 0;
    }
};