class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto i : strs){
            string key = getkey(i);
            m[key].push_back(i);
        }
        vector<vector<string>> res;
        for(auto it : m)
        {
            res.push_back(it.second);
        }
        return res;
    }

    string getkey(string s){
        vector<int> count(26,0);
        for(auto i : s)
            count[i-'a']++;
        string key;
        for(int i = 0 ; i< 26 ; i++){
            key.append(to_string(count[i] + 'a'));
        }
        return key;
    }
};