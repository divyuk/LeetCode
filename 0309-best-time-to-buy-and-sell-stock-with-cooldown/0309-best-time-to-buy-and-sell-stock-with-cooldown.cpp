class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
        
       if ( i >= prices.size()) return 0;
        int profit =0;
        
        if( dp[i][buy]!= -1) return dp[i][buy];
        if(buy)
            profit = max(-prices[i]+ f(i+1, 0, prices,dp) , 0+f(i+1, 1, prices, dp));
        
        else
            profit = max(prices[i]+f(i+2, 1, prices,dp) , 0+f(i+1,0,prices, dp) );
        
            return  dp[i][buy]= profit;
        
    }
    
    int maxProfit( vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};