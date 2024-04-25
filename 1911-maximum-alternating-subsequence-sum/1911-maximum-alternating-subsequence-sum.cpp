#define ll long long

class Solution {
private:
    long long f(vector<int>& nums, int idx, bool flag, vector<vector<ll>>& dp) {
        if (idx >= nums.size()) return 0;
        
        if (dp[idx][flag] != -1) return dp[idx][flag];
        
        ll notTake = f(nums, idx + 1, flag, dp);
        
        ll val = nums[idx];
        if (!flag) val = -val; // Simplified condition
        ll take = f(nums, idx + 1, !flag, dp) + val;
        
        return dp[idx][flag] = max(take, notTake);
    }
    
public:
    long long maxAlternatingSum(vector<int>& nums) {
        bool flag = true;
        int n = nums.size();
        // vector<vector<ll>> dp(n+1, vector<ll>(2, -1));
        // return f(nums, 0, flag, dp);
        vector<vector<ll>> dp(n+1, vector<ll>(2, 0)); // 0: even 1 : odd
        
        for(int i = 1; i<n+1 ; i++){
            // Even
            dp[i][0] = max(dp[i-1][1] - nums[i-1]  , dp[i-1][0]  );
            dp[i][1] = max(dp[i-1][0] + nums[i-1] , dp[i-1][1] );
        }
        return max(dp[n][0] , dp[n][1]);
    }
};
