class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans =0;
        int sum =nums[0];
        int n =nums.size();
        for (int i = 1; i < n; i++)
        {
                if(nums[i]>nums[i-1]){
                   sum+=nums[i];
                   ans=max(sum,ans);
                }
                else
                    sum=nums[i];
        }
        return max(ans,*max_element(nums.begin() , nums.end()));
    }
};