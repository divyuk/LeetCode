class Solution {
public:
    string sortSentence(string s) {
        string word;
        vector<string>v(10);
        for(int i = 0;i<s.size();i++){
            if(s[i]>=48 and s[i]<=57){
                v[s[i]-48] = word+" ";
                i++;
                word="";
            }
            else word+=s[i];
        }
        string ans;
        for(auto x : v)
            ans+=x;
        ans.pop_back();
        return ans;
    }
};