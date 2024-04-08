class Solution {
public:
    
    int solve(int idx , int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(idx == nums.size()) return 0;
        int take=0;
        
        if(prev!=-1 and dp[prev][idx]!=-1) return dp[prev][idx];
        
        if(prev==-1 or nums[prev]<nums[idx]  ) take = 1 + solve(idx+1, idx, nums,dp);
        
            
        int notTake = solve(idx+1 , prev, nums,dp );
        
        if(prev!=-1) dp[prev][idx] = max(take, notTake);
        return max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};