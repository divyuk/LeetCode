class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            
            // Check if left half is sorted
            else if(nums[low] <= nums[mid] ){
                // this means element is definetaly in left half
                if(nums[low] <= target and target < nums[mid])
                    high = mid-1;
                else
                    low=mid+1;
                
            }
            else{
                if(nums[mid]<target and target <= nums[high])
                    low = mid +1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};