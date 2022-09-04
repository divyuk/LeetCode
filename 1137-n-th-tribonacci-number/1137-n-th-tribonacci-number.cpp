class Solution {
public:
    
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        
    }
    
    int solve(int n,vector<int>&dp){
        if(dp[n]!=-1) return dp[n];
        else if(n==0) return dp[0]=0; 
        else if(n==1 || n==2) return dp[n]=1;
        else return dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    }
    
};