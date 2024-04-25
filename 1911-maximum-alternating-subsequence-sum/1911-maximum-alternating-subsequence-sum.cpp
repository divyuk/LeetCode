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
        vector<vector<ll>> dp(nums.size(), vector<ll>(2, -1));
        return f(nums, 0, flag, dp);
    }
};
