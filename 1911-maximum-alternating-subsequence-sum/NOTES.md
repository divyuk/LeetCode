long long maxAlternatingSum(vector<int>& nums) {
bool flag = true;
int n = nums.size();
// vector<vector<ll>> dp(n+1, vector<ll>(2, -1));
// return f(nums, 0, flag, dp);
vector<vector<ll>> dp(n+1, vector<ll>(2, 0)); // 0: even 1 : odd
for(int i = 1; i<n+1 ; i++){
// Even
dp[i][0] = max(dp[i-1][1] - nums[i-1]  , dp[i-1][0]  );
dp[i][1] = max(dp[i-1][0] + nums[i-1] , dp[i-1][1] );
}
// Print the dp array
cout << "DP array:" << endl;
for(int i = 0; i <= n; i++) {
cout << dp[i][0] << " " << dp[i][1] << endl;
}
return max(dp[n][0] , dp[n][1]);
}