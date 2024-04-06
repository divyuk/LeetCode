class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); // Initialize dp array with INT_MAX
        dp[0] = 0; // Base case: 0 coins needed to make 0 amount

        for (int j = 1; j <= amount; ++j) {
            for (int i = 0; i < coins.size(); ++i) {
                if (coins[i] <= j && dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};