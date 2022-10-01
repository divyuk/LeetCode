class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        int right=0,left=0;
        while (right<n)
        {
            if(nums[right] == 0){
                if(k!=0)
                    k--; // decrease the k
                else
                    while(nums[left++] != 0);
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};