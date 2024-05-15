#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<pair<int,int>> dir{{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool bfs(vector<vector<int>>& mat, int n, int mid) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        if(mat[0][0] < mid) return false;
        
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if (x == n - 1 && y == n - 1) return true;

            for (pair<int,int> d : dir) {
                int xx = x + d.first;
                int yy = y + d.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && !visited[xx][yy] && mat[xx][yy] >= mid) {
                    visited[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
        }
        return false;
    }

    void calculateManhattanDist(vector<vector<int>>& mat, int n) {
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Push all thieves into the queue and mark them as visited
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<int,int> curr = q.front();
            int x = curr.first;
            int y = curr.second;
            q.pop();
            mat[x][y] = level; // Set the Manhattan distance at this cell

            for (pair<int,int> d : dir) {
                int xx = x + d.first;
                int yy = y + d.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && !visited[xx][yy]) {
                    visited[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
        }
        level++;
    }
}


public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(grid.begin(), grid.end());
        calculateManhattanDist(mat, n);
        
        
        int low = 0, high = n, res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (bfs(mat, n, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};
