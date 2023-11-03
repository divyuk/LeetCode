class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) {
            return result;
        }
        
        int m = heights.size();
        int n = heights[0].size();
        
        // Create two boolean grids to mark if water can reach the Pacific and Atlantic Oceans.
        vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));
        
        // DFS to check if water can flow from each cell to the Pacific Ocean.
        for (int i = 0; i < m; i++) {
            dfs(heights, canReachPacific, i, 0);
            dfs(heights, canReachAtlantic, i, n - 1);
        }
        
        for (int j = 0; j < n; j++) {
            dfs(heights, canReachPacific, 0, j);
            dfs(heights, canReachAtlantic, m - 1, j);
        }
        
        // Check if water can flow to both the Pacific and Atlantic Oceans and add to the result.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& canReach, int r, int c) {
        if (canReach[r][c]) {
            return;
        }
        
        canReach[r][c] = true;
        int m = heights.size();
        int n = heights[0].size();
        
        // Check and explore neighboring cells.
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& dir : directions) {
            int newRow = r + dir.first;
            int newCol = c + dir.second;
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[r][c]) {
                dfs(heights, canReach, newRow, newCol);
            }
        }
    }
};
