class Solution {
public:
    
    int f(int idx, vector<int>&coins , int target, vector<vector<int>>cache){
        if(idx==0){
            if(target % coins[0]==0)  return target/coins[0];
            return 1e9;
        }
        if(cache[idx][target]!=-1) return cache[idx][target];
        
        int notTake = f(idx-1, coins, target,cache);
        int take=INT_MAX;
        if(coins[idx] <= target) take = 1+ f(idx, coins, target-coins[idx],cache);
        
        return cache[idx][target] =  min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>cache(n+1,vector<int>(amount+1, -1));
        
        for(int a = 0; a<=amount ; a++){
            if(a%coins[0] == 0 ) cache[0][a] = a/coins[0];
            else
                cache[0][a] = 1e9;
        }
        
        for(int i = 1 ; i< n; i++){
            for(int t = 0; t<=amount; t++){
                int notTake = cache[i-1][t];
                int take=INT_MAX;
                if(coins[i] <= t) take = 1+ cache[i][t-coins[i]];
                cache[i][t] =  min(take,notTake);
            }
        }
        
        return (cache[n-1][amount]>=1e9) ? -1 : cache[n-1][amount];
        
//         int ans= f(n-1, coins, amount, cache);
      
//         if(ans>=1e9) return -1;
//         return ans;
    }
};