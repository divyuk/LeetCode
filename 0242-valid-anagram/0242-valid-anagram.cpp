class Solution {
public:
    bool isAnagram(string s, string t) {
    
        int ns = s.size();
        int ts = t.size();
        
        if(ns!=ts) return 0;
        
        vector<int>v(26,0);
        vector<int>v2(26,0);
        for(int i =0;i<ns;i++){
            v[s[i] - 'a']++;
        }
        
        for(int i =0;i<ts;i++){
            v2[t[i] - 'a']++;
        }
        for(int i =0;i<26;i++){
            if(v[i] != v2[i])
                return 0;
        }
        return 1;
    }
};