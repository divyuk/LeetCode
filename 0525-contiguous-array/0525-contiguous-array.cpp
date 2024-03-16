class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumIndexMap;
        int max_len = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                sum -= 1;
            } else {
                sum += 1;
            }

            if (sum == 0) {
                max_len = i + 1;
            } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
                max_len = max(max_len, i - sumIndexMap[sum]);
            } else {
                sumIndexMap[sum] = i;
            }
        }

        return max_len;
    }
};
