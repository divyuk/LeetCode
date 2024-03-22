class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>productArray(size,0);
        int previous = 1;
        productArray[0] = 1;
        
        for(int index = 1; index<size;index++){
            productArray[index] = previous * nums[index-1];
            previous = productArray[index];
        }
        previous  = 1;
        for(int index = size-1; index>=0 ;index--){
            productArray[index] = previous * productArray[index];
            previous *= nums[index];
        }
          
        
        return productArray;
    }
};