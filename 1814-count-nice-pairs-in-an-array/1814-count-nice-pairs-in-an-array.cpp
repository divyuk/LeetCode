class Solution {
public:
    int rev(int n) {
        int reverse_number = 0;
        while (n != 0) {
            int r = n % 10;
            reverse_number = 10 * reverse_number + r;
            n /= 10;
        }
        return reverse_number;
    }

    int countNicePairs(std::vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int c = 0;
        unordered_map<int ,int>freq;
        
        for(int i =0;i<n; i++){
            int diff = nums[i] - rev(nums[i]);
            
            c = (c+freq[diff])%MOD;
            
            freq[diff]++;
        }
        return c;
    }
};
