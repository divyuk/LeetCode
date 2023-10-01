class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res;
        string ans;
        for(auto i : s){
            if(i != ' ')
                ans.push_back(i);
            else{
                reverse(ans.begin(),ans.end());
                res+=ans+' ';
                ans ="";
            }
        }
        reverse(ans.begin(),ans.end());
        return res+ans;
    }
};