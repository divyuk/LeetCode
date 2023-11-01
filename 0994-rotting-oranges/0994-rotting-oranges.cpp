#include <vector>
#include <queue>

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int cx, int cy) {
        return (cx >= 0 && cy >= 0 && cx < r && cy < c && grid[cx][cy] == 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        int time = 0, fresh = 0;

        // Starting filling the queue with the source (rotten oranges)
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if (fresh == 0) return 0;

        while (!q.empty()) {
            int size = q.size();  // Calculate the current size of the queue
            int t = 0;
            
            // Take out the first orange from the queue
            while (size > 0) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                
                for (int i = 0; i < 4; i++) {
                    int move_x = x + dx[i];
                    int move_y = y + dy[i];
                    if (isValid(grid, r, c, move_x, move_y)) {
                        q.push({move_x, move_y});
                        t++;
                        grid[move_x][move_y] = 2;
                    }
                }
                size--;
            }
            
            if (t) time++;
        }
         for(int i = 0 ; i<r;i++){
            for(int j = 0 ; j<c; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return  time; 
    }
};
