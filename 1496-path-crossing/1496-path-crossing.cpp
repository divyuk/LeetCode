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
            if(s.find({x,y}) != s.end()) return true;
            else s.insert({x,y});
        }

        return false;
    }
};
