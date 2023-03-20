class Solution {
public:
    void merge(vector<int>& nums,int l,int mid , int h , int &count){
        vector<int>temp(h-l+1,0);
        int i =l,k=0,j=mid+1;
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
        while(i<=mid) temp[k++] = nums[i++];
        while(j<=h) temp[k++] = nums[j++];
        
        k=0;
        while(l<=h) nums[l++] = temp[k++];
    }
    void mergeSort(vector<int>& nums,int l,int h , int &count){
        if(l<h){
            int mid = (l+h)/2;
            mergeSort(nums,l,mid,count);
            mergeSort(nums,mid+1,h,count);
            merge(nums,l,mid,h,count);

        }
    }

    int reversePairs(vector<int>& nums) {
        int count =0;
        int l =0,h=nums.size()-1;
        mergeSort(nums,l,h,count);
        for(int i : nums) cout<<i<<" ";
        return count;
    }
};