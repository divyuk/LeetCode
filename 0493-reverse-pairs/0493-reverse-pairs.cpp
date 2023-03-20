class Solution {
public:
    void mergeSort(vector<int>& nums, int l , int h , int &count){
        if(l==h) return;
        
        int mid = (l+h)/2;
        
        mergeSort(nums,l,mid,count);
        mergeSort(nums,mid+1,h,count);
        
        vector<int> temp(h-l+1,0);
        int i = l, j = mid+1, k = 0;
        
        while(i <= mid && j <= h){
            if(nums[i] <= 2LL*nums[j]){
                i++;
            }
            else{
                count += mid-i+1;
                j++;
            }
        }
        
        i = l, j = mid+1, k = 0;
        while(i <= mid && j <= h){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= h)   temp[k++] = nums[j++];
        
        k = 0;
        while(l <= h){
            nums[l++] = temp[k++];
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size()-1;
        mergeSort(nums, 0, n, count);
        return count;
    }
};
