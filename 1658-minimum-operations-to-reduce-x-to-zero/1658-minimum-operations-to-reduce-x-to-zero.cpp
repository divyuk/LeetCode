class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int maxLength = -1,currSum =0, n = nums.size();
        for(int l =0, r=0; r<n ; ++r){
            currSum += nums[r];
            while(l<=r and currSum >sum-x) currSum -= nums[l++];
            if(currSum == sum - x) maxLength = max(maxLength, r-l+1);
        }
        return maxLength == -1  ? -1 :n -  maxLength;
    }
};