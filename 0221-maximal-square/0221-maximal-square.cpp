class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
         int maxsqlen = 0;
        vector<vector<int>>dp(r+1, vector<int>(c+1,0));
        for(int i = 1; i<=r; i++){
            for(int j =1 ; j<=c ; j++){
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1+ min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]) );
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
                
            }
        }
        return maxsqlen*maxsqlen;
    }
};