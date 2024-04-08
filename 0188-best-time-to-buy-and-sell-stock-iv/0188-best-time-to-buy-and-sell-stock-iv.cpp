class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp, int k) {
        if (k == 0 || i == prices.size()) return 0;
        int profit = 0;

        if (dp[i][buy][k] != -1) return dp[i][buy][k];

        if (buy)
            profit = max(-prices[i] + f(i + 1, 0, prices, dp, k), f(i + 1, 1, prices, dp, k));
        else
            profit = max(prices[i] + f(i + 1, 1, prices, dp, k - 1), f(i + 1, 0, prices, dp, k));

        return dp[i][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, prices, dp, k);
    }
};