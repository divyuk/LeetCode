class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0;
        int n1 =  A.size();
        int n2 =  B.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        int r = dp.size();
        int c = dp[0].size();
        for (int i = 1; i <r; i++) {
            for (int j = 1; j<c; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};