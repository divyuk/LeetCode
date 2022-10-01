class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        int right=0,left=0;
        while (right<n)
        {
            if(nums[right] == 0) k--;
            if(k<0 and nums[left++] == 0) k++;
            right++;
        }
      
        return right-left;
    }
};