#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        for (char c : s)
            umap[c]++;
        
        // Sorting the characters based on their frequencies
        map<int, string, greater<int>> sortedMap;
        for (auto& entry : umap) {
            sortedMap[entry.second] += entry.first;
        }
        
        // Construct the result string
        string ans = "";
        for (auto& entry : sortedMap) {
            for (char c : entry.second) {
                for (int i = 0; i < entry.first; ++i) {
                    ans += c;
                }
            }
        }
        return ans;
    }
};
