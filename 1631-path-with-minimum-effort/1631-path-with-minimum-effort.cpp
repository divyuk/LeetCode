class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        min_heap.push({0, 0, 0});

        while (!min_heap.empty()) {
            auto curr = min_heap.top();
            int dh = curr[0];
            int i = curr[1];
            int j = curr[2];
            min_heap.pop();
            
            if (visited[i][j]) continue;
            if (i == row - 1 && j == col - 1) return dh;
            // visited[i][j] = true;
            
            for (auto& p : dir) {
                int ni = i + p.first;
                int nj = j + p.second;
                if (ni >= 0 && ni < row && nj >= 0 && nj < col && !visited[ni][nj]) {
                    int new_dh = max(dh, abs(heights[ni][nj] - heights[i][j]));
                    min_heap.push({new_dh, ni, nj});
                     visited[i][j] = true;
                }
            }
        }
        return 0;
    }
};