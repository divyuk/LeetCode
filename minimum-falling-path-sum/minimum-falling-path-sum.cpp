#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the first row of dp with values from matrix
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize dp[i][j] with matrix[i][j]
                dp[i][j] = matrix[i][j];

                // Choose the minimum from the previous row
                int best_prev = dp[i - 1][j];
                if (j > 0) {
                    best_prev = min(best_prev, dp[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    best_prev = min(best_prev, dp[i - 1][j + 1]);
                }

                dp[i][j] += best_prev;
            }
        }

        // Find the minimum value in the last row
        int min_sum = INT_MAX;
        for (int j = 0; j < n; j++) {
            min_sum = min(min_sum, dp[n - 1][j]);
        }

        return min_sum;
    }
};
