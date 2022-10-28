class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -10000,ans=-10000;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum=max(nums[i],sum+nums[i]);
            cout<<sum<<"\n";
            ans = max(ans,sum);
        }
        return ans;
    }
};