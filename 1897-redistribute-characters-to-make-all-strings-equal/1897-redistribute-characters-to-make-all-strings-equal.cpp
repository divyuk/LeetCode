class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>um; int n = words.size();
        for(auto w : words){
            for(auto c : w) um[c]++;
        }
        for(auto c : um){
            if(c.second%n!=0) return false; 
        }
        return true;
    }
};