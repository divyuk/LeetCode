#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
       unordered_set<string> destinations;
        
        for(const auto& path : paths) {
            destinations.insert(path[1]);
        }
        
        for(const auto& path : paths) {
            destinations.erase(path[0]);
        }
        
        return *destinations.begin();
    }
};
