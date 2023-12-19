class Solution {
public:
    
    bool isValid(int i , int j, int m, int n ){
        return (i>=0 and i<m and j>=0 and j<n);
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int diry[] = {0,0,1,-1,1,-1,-1,1};
        for(int i = 0;i<m;i++){
            for(int j =0; j<n ;j++){
                int sum = img[i][j],cnt=1;
                for(int x = 0; x<8; ++x){
                    int dx = i+dirx[x];
                    int dy = j+diry[x];
                    if(isValid(dx, dy, m,n)){
                        sum+=img[dx][dy];
                        cnt++;
                    }
                }
                    int avg = sum/cnt;
                    ans[i][j]=avg;
            }
        }
        
        
        return ans;
    }
};