class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> map;
        int ans =0;
        for (const auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                map[sum]++;
                ans = max(ans, map[sum]);
            }
        }
        return wall.size() - ans;
    }
};
