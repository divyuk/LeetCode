class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return count(n,dp);

    }
    
private:
    int count(int n , vector<int>&dp){
        if( n == 0) return 1;
        if(n<0)  return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = count(n-1,dp) + count(n-2,dp);
    }
};