class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
         int maxsqlen = 0;
        vector<vector<int>>dp(r+1, vector<int>(c+1,0));
        for(int i = r-1; i>=0; i--){
            for(int j =c-1 ; j>=0 ; j--){
                if(matrix[i][j] == '1') {
                    dp[i][j] = 1+ min(dp[i+1][j+1] , min(dp[i+1][j] , dp[i][j+1]) );
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
                
            }
        }
        for(int i =0;i<=r; i++){
            for(auto it : dp[i]) cout<<it<<" ";
            cout<<"\n";
        }
        return maxsqlen*maxsqlen;
    }
};