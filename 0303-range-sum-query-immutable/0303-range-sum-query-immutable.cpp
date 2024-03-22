class NumArray {
private:
    vector<int>prefixSum;
public:
    
    NumArray(vector<int>& nums) {
        int length = nums.size();
        prefixSum.resize(length);
        prefixSum[0] = nums[0];
        
        for(int index=1;index<length; index++){
            prefixSum[index] = prefixSum[index-1] + nums[index];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */