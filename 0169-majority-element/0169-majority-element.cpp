class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majorElemnt = nums[0];
        int arraySize = nums.size();
        for(int index = 1; index< arraySize ; ++index){
            
            (majorElemnt ==  nums[index]  ) ? count++ : count--;
            
            if(count==0){
                majorElemnt  = nums[index];
                count = 1;
            }
        }
        
        return majorElemnt;
    }
};