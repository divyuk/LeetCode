class Solution {
public:
    int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(m + 1, 0));
        
        for (int i = m - 1; i >= 0; i--) {
            for (int left = i; left >= 0; left--) {
                int mult = multipliers[i];
                int right = n - 1 - (i - left);
                dp[i][left] = std::max(mult * nums[left] + dp[i + 1][left + 1], 
                                       mult * nums[right] + dp[i + 1][left]);
            }
        }
        
        return dp[0][0];
    }
};