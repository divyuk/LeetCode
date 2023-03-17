class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k = k%n;
        reverse(nums.begin() , nums.end()-k);
        reverse(nums.end()-k , nums.end());
        reverse(nums.begin() , nums.end());
    }
};