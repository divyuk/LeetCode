class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() ,nums.end());
        long i =0,j=0,total=0,res=1;;
        
        while(j<n){
            total+=nums[j];
            
            while((long)(j-i+1)*nums[j] > total + k){
                total-=nums[i];
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};