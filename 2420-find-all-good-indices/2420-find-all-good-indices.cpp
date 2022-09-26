class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>good;
        int n = nums.size();
        vector<int>dec_left(n+1,1),inc_right(n+1,1);
        for(int i = 1;i<n;i++){
            if(nums[i]<=nums[i-1])
                dec_left[i] = dec_left[i-1]+1;
        }
        for(int i = n-2;i>=0;i--){
            if(nums[i+1]>=nums[i])
                inc_right[i] = inc_right[i+1]+1;
        }
        
        for(int i = k;i<n-k;i++){
            if(dec_left[i-1]>=k and inc_right[i+1]>=k )
                good.push_back(i);
        }
        return good;
    }
};