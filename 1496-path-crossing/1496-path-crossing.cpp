class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> s;
        int x = 0, y = 0;
        s.insert({x, y}); 
        for (char c : path) {
            if (c == 'N') y += 1;
            else if (c == 'S') y -= 1;
            else if (c == 'W') x -= 1;
            else if (c == 'E') x += 1;
            // Check if the current position has been visited before
            if (!s.insert({x, y}).second) {
                return true;
            }
        }

        return false;
    }
};
