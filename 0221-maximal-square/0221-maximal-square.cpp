class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int maxsqlen = 0;
        std::vector<int> dp(c + 1, 0);
        int prev = 0; // Store the value of dp[i+1][j+1] from the previous iteration

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                int temp = dp[j]; // Store the current value of dp[j] before updating it
                if (matrix[i][j] == '1') {
                    dp[j] = 1 + std::min(prev, std::min(dp[j], dp[j + 1]));
                    maxsqlen = std::max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0; // Reset to 0 if the current cell is '0'
                }
                prev = temp; // Update prev for the next iteration
            }
        }

        return maxsqlen * maxsqlen;
    }
};