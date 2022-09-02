class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n<2) return n;
        if(dp[n]!=-1) return dp[n];
        return  dp[n] = f(n-1,dp)+f(n-2,dp);
    }
    int fib(int n) {
        // vector<int>dp(n+1,-1);
        // return f(n , dp);
        if(n<2) return n;
        // dp[0] = 0;
        // dp[1] = 1;
        int prev = 1;
        int prev2 = 0;
        for(int i = 2 ; i<=n;i++){
            int curr =  prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};