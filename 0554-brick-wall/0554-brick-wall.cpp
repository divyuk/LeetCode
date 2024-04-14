class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> map;
        
        for (const auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                if (map.find(sum) != map.end())
                    map[sum]++;
                else
                    map[sum] = 1;
            }
        }
        
        int res = wall.size();
        for (const auto& pair : map)
            res = min(res, static_cast<int>(wall.size()) - pair.second);
        
        return res;
    }
};
