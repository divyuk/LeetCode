class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum =0,maxsum=nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(currsum<0)
                currsum=0;
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};