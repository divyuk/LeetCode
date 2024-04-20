class Solution {
    void dfs(vector<vector<int>>& land,int m, int n, int i, int j, int &bi,int &bj){
        land[i][j] = 0;
        
        bi = max(bi,i);
        bj = max(bj,j);
        
        vector<pair<int,int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
        for(pair<int,int>dir : directions){
            int x = i + dir.first;
            int y = j + dir.second;
            if(x>=0 and x<m and y>=0 and y<n and land[x][y]==1){
                dfs(land,m,n,x,y,bi,bj);
            }
        }
}   
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>>ans;
        for(int i = 0; i<m; i++){
            for(int j =0;j<n; j++){
                if(land[i][j] == 1){
                    int bi = 0, bj =0;
                    dfs(land,m,n,i,j, bi,bj);
                    ans.push_back({i,j,bi,bj});
                }
                
            }
        }
        return ans;
    }
};