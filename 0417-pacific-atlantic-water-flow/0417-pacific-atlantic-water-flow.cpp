class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;

        //? Check from Pacific Left --> and Atlantic <-- right

        for (int i = 0; i < m; i++)
        {
            dfs(heights, canReachPacific, m, n, i, 0);
            dfs(heights, canReachAtlantic, m, n, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(heights, canReachPacific, m, n, 0, i);
            dfs(heights, canReachAtlantic, m, n, m - 1, i);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (canReachPacific[i][j] and canReachAtlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>>& canReach, int m, int n, int r, int c)
    {
        if (canReach[r][c])
            return;
        canReach[r][c] = true;
        vector<pair<int, int>> directions = { {1, 0},
                                              {-1, 0},
                                              {0, 1},
                                              {0, -1} };

        for (pair<int, int> &dir : directions)
        {
            int newRow = r + dir.first;
            int newColumn = c + dir.second;

            if (newRow >= 0 and newRow < m and newColumn >= 0 and newColumn < n and heights[r][c] <= heights[newRow][newColumn])
                dfs(heights, canReach, m, n, newRow, newColumn);
        }
    }
};