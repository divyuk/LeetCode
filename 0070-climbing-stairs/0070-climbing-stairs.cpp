class Solution {
private:
    int count(int n , vector<int>&dp){
        if( n == 0) return 1;
        if(n<0)  return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = count(n-1,dp) + count(n-2,dp);
    }
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // return count(n,dp);
        
        if(n==0 or n == 1) return 1;
        if(n==2) return 2;
        int prev2 = 1;
        int prev = 2;
        int nth = 0;
        for(int i =3; i <= n ;i++){
            nth = prev  +prev2;
            prev2 = prev;
            prev = nth;
        }
        return prev;
    }
    

};