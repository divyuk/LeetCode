class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int left = 0, right =n-1, mid=0;
        while(left<=right){
            mid= left + (right-left)/2;
            if(mid-1>=0 and nums[mid]<=nums[mid-1] ) return nums[mid];
            else if(nums[mid]>nums[n-1]) left=mid+1;
            else if(nums[mid] < nums[n-1]) right = mid-1;
        }
        return nums[mid];
    }
};