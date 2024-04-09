class Solution {
public:
    int solve(int i , int n , string &s, vector<int>&dp){
        if(i==n)  return  dp[i] = 1;
        if(s[i] == '0')  return dp[i] = 0;
        if(dp[i] != -1) return dp[i];
        
        int onechar =solve(i+1,n,s, dp);
        int twochar =0;
        
        if(i+1<n){
            if(s[i] == '1' or (s[i] == '2' and s[i+1] <='6') ) 
                twochar = solve(i+2, n, s, dp);
        }
        
        return dp[i] = onechar + twochar;
    }
    
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[n] =  1;
        for(int i = n-1 ;i>=0; i--){
            if(s[i] == '0')  dp[i] = 0;
            else{
               dp[i] = dp[i+1];
                if(i+1<n){
                if(s[i] == '1' or (s[i] == '2' and s[i+1] <='6') ) 
                    dp[i] += dp[i+2];
                }
            }
          
        }
        
        return dp[0];
    }
};