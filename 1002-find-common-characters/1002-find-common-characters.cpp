#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        unordered_map<char,int> umap;
        
        // Count occurrences of characters in the first word
        for(auto c : words[0]) 
            umap[c]++;
        
        // Update the counts based on characters in subsequent words
        for(int i = 1; i < n; i++) {
            unordered_map<char, int> tempMap;
            for(char c : words[i]) {
                if(umap.find(c) != umap.end() && umap[c] > 0) {
                    tempMap[c]++;
                    umap[c]--;
                }
            }
            umap = tempMap; // Update umap to keep track of common characters
        }
        
        // Add common characters to the result vector
        for(auto it : umap) {
            char k = it.first;
            int count = it.second;
            while(count > 0) {
                ans.push_back(string(1, k));
                count--;
            }
        }
        
        return ans;
    }
};
