class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right =n-1;
        while(left < right) {
            
            int mid = (left + right) /2;
            if( (mid%2==0 and nums[mid] == nums[mid+1] ) or ( mid%2==1 and nums[mid] == nums[mid-1]) )
                left = mid  +1;
            else
                right = mid;
        }
        return nums[right];
    }
};