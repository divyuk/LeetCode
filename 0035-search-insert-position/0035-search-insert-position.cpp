class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid=0;
        while(low<=high){
            mid = (low+high)/2;
            if(target == nums[mid]) return mid;
              else if(nums[mid]>target) {
                if(mid ==0 or nums[mid-1] < target) return mid;
                high = mid-1;
            }
            else low = mid+1;
          
            
        }
        if(nums[nums.size()-1] < target) return nums.size();
        else if (nums[0] > target  ) return 0;
        return 0;
    }
};