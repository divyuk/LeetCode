```
class Solution {
public:
int f(int idx, vector<int>&coins , int target,vector<vector<int>>&cache){
if(idx==0) return target%coins[0]==0;
if(cache[idx][target] !=-1) return cache[idx][target];
int notTake = f(idx-1, coins, target , cache);
int take=0;
if(coins[idx] <= target) take = f(idx, coins, target-coins[idx] , cache);
return cache[idx][target] = take+notTake;
}
int change( int amount, vector<int>& coins) {
int n = coins.size();
vector<vector<int>>cache(n,vector<int>(amount+1,-1));
return f(n-1, coins, amount, cache);
}
};
```
​
​
​
​
​