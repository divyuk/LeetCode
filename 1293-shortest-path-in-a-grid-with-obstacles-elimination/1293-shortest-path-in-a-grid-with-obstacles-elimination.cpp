#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        // Instead of fixed sizes, we use the size of grid
        bool visited[r][c][k+1];
        memset(visited, false, sizeof(visited));
        queue<vector<int>> q;
        int i = 0, j = 0;
        q.push({i, j, k, 0}); // Add the initial step count as well

        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            vector<int> temp = q.front();
            q.pop();
            int currI = temp[0];
            int currJ = temp[1];
            int obs = temp[2];
            int steps = temp[3]; // Retrieve the steps taken so far

            if (currI == r-1 && currJ == c-1)
                return steps;

            for (pair<int,int> dir : directions) {
                int newI = currI + dir.first;
                int newJ = currJ + dir.second;

                if (newI >= 0 && newI < r && newJ >= 0 && newJ < c) {
                    if (grid[newI][newJ] == 0 && !visited[newI][newJ][obs]) {
                        q.push({newI, newJ, obs, steps + 1});
                        visited[newI][newJ][obs] = true;
                    }
                    else if (grid[newI][newJ] == 1 && obs > 0 && !visited[newI][newJ][obs-1]) {
                        q.push({newI, newJ, obs - 1, steps + 1});
                        visited[newI][newJ][obs - 1] = true;
                    }
                }
            }
        }
        return -1;
    }
};
