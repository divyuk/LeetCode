class Solution {
public:
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix_sum(n + 1);
    unordered_map<int, int> map;
    int count = 0;
    map[0] = 1;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = (prefix_sum[i - 1] + nums[i - 1]) % k;
        if (prefix_sum[i] < 0) {
            prefix_sum[i] += k;
        }
        count += map[prefix_sum[i]];
        map[prefix_sum[i]]++;
    }
    return count;
}

};