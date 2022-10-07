class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int k = edges[1][0] == edges[0][0] or edges[1][1] == edges[0][0] ? edges[0][0] : edges[0][1];
        return k;
    }
};