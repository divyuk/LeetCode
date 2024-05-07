class Solution {
    struct T {
        int height, r, c;
        T(int x, int y, int z) : height(x), r(y), c(z){}
        bool operator< (const T &d) const {return height > d.height;}
    };
    typedef pair<int, pair<int,int>> P; // {height , i,j}
    vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // priority_queue<P,vector<P>, greater<>> pq; // min heap
        priority_queue<T>pq;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        pq.push(T(grid[0][0] , 0 , 0));
        // pq.push({grid[0][0] ,{0,0}});
        
        while(!pq.empty()){
            auto curr = pq.top();
            int h = curr.height;
            int i = curr.r;
            int j = curr.c;
            if(i==n-1 and j == n-1) return h;
            pq.pop();
            for(pair<int,int>p : dir){
                int x = i + p.first;
                int y = j + p.second;
                if(x>=0 and x<n and y>=0 and y<n and !visited[x][y]){
                    pq.push( T(max(grid[x][y], h) , x,y )  );
                    visited[x][y] = 1;
                }
            }
        }
        return 0;
    }
};