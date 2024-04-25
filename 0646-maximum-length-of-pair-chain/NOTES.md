Recustion + Memoization
​
```
class Solution {
int solve(int idx, int prev, vector<vector<int>>& pairs,vector<vector<int>>&dp){
if(idx>=pairs.size()) return 0;
if(prev!=-1 and dp[idx][prev]  != -1) return dp[idx][prev];
int take=0;
if(prev== -1 or pairs[prev][1] < pairs[idx][0])
take = 1 + solve(idx+1, idx, pairs, dp);
int notTake = solve(idx+1, prev , pairs, dp);
if(prev!= -1) dp[idx][prev] = max(take,notTake);
return max(take,notTake);
}
public:
int findLongestChain(vector<vector<int>>& pairs) {
int n = pairs.size();
sort(pairs.begin() , pairs.end());
vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
return solve(0, -1, pairs, dp);
}
};
```
---
​
Bottom Up
​
​
​