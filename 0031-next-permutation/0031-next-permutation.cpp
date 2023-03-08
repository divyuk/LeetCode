class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        int idx = -1;
        for(int i = nums.size()-1 ; i>0 ; i--){
            if (nums[i]>nums[i-1]){
                idx = i;
                break;
            }
        }
        if(idx==-1)
            reverse(nums.begin() , nums.end());
        else{
            int m = 100000;int k =idx;
            for(int j = idx+1 ; j<nums.size() ; j++){
                if(nums[idx-1]<nums[j] ){
                    m = min(m , nums[j]);
                    k = j;
                }
            }
            swap(nums[k] , nums[idx-1]);
            reverse(nums.begin()+idx , nums.end());
        }
        
    }
};


