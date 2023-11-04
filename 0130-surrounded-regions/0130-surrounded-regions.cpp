/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution
{
public:
    void convertor(vector<vector<char>> &board, int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'B')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    bool valid(vector<vector<char>> &board, int m, int n, int r, int c)
    {
        if (r >= 0 and r < m and c >= 0 and c < n and board[r][c] == 'O')
            return true;
        return false;
    }

    void dfs(vector<vector<char>> &board, int m, int n, int r, int c)
    {
        board[r][c] = 'B';

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (pair<int, int> direction : directions)
        {
            int newRow = r + direction.first;
            int newCol = c + direction.second;
            if (valid(board, m, n, newRow, newCol))
                dfs(board, m, n, newRow, newCol);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            // T ->B
            if (board[i][0] == 'O')
                dfs(board, m, n, i, 0);
            if (board[i][n - 1] == 'O')
                dfs(board, m, n, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            // L ->R
            if (board[0][i] == 'O')
                dfs(board, m, n, 0, i);
            if (board[m - 1][i] == 'O')
                dfs(board, m, n, m - 1, i);
        }

        convertor(board, m, n);
    }
};
// @lc code=end
