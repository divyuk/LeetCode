class Solution {
public:
    
    void solve(int i , string s , vector<string>&ps , vector<vector<string>>&res){
        if(i == s.size()){
            res.push_back(ps);
            return;
        }
        for(int j = i ; j<s.size() ; j++){
            if(palindromic(s , i , j)){
                ps.push_back(s.substr(i,j-i+1));
                solve(j+1 , s , ps , res);
                ps.pop_back();
            }

        }
    }

    bool palindromic(string s , int start,  int end){
        while (start<=end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
        
    }
    vector<vector<string>> partition(string s){
        vector<string>ps;
        vector<vector<string>>res;
        solve(0,s,ps , res);
        return res;
    }
};