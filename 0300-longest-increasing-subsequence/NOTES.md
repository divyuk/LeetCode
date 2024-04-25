}
};
```
​
​
​
**For Bottom Up:**
​
dp array  = [     *i*  ] will tell the LIS ending at *i*
​
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n = nums.size();
vector<int>dp(n+1, 1);
int maxLIS = 1;
for(int i = 0 ; i< n ; i++){
for(int j = 0 ; j<i ; j++){
if(nums[j] < nums[i]){
dp[i] = max(dp[i] , dp[j] + 1);
maxLIS = max(maxLIS , dp[i]);
}
}
}
return maxLIS;
}
};
```
TC : O(n^2) SC : O(n)
---
​
​