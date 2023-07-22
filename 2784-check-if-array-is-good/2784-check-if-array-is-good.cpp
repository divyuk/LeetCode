class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxel = *max_element(nums.begin(), nums.end());
        if(nums.size()-1 !=maxel) return 0;
        int total = accumulate(nums.begin() , nums.end(), 0);
        int original = (maxel*(maxel+1)/2) +maxel;
        return(total == original);
    }
};