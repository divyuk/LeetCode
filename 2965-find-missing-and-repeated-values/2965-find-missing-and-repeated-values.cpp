class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> store(n * n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                store[grid[i][j] - 1]++;
            }
        }
        vector<int> ans(2, 0);
        for (int i = 0; i < n * n; i++) {
            if (store[i] == 0) {
                ans[1] = i + 1;
            }
            if (store[i] > 1) {
                ans[0] = i + 1;
            }
        }
        return ans;
    }
};
