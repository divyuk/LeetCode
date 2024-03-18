class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        int arrows = 1;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int firstBalloon = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            int secondBalloon = points[i][0];
            if (secondBalloon <= firstBalloon) {
                // Update to the end of the current balloon
                firstBalloon = min(firstBalloon, points[i][1]);
            } else {
                // New arrow needed, update to the end of the current balloon
                arrows++;
                firstBalloon = points[i][1];
            }
        }

        return arrows;
    }
};
