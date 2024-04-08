class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        typedef pair<int, pair<int, int>> corr; // coordinates
        // will have min heap
        priority_queue<corr, vector<corr>, greater<corr>> kclose;

        for (vector<int>& point : points) {
            int x = point[0];
            int y = point[1];
            int d = x * x + y * y; // Avoiding square root for actual distance
            kclose.push({d, {x, y}});
        }

        while (k-- > 0) {
            corr curr = kclose.top();
            kclose.pop();
            vector<int> temp = {curr.second.first, curr.second.second};
            ans.push_back(temp);
        }
        return ans;
    }
};