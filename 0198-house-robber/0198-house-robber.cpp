class Solution {
public:
    
    int f( int n ,  vector<int>&nums, vector<int> &dp){
        
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1 ) return dp[n];
        int take = nums[n] + f(n-2,nums, dp);
        int notTake = f(n-1,nums, dp);
        return dp [n] = max(take , notTake);
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(n-1, nums, dp);
    }
};