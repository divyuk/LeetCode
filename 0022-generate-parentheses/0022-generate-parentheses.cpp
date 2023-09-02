class Solution {
public:
    void genrate(int n , vector<string>&res,string para,int open, int close){
        if(open == n && close == n){
            res.push_back(para);
            return;
        }
        if(open<n){
            genrate(n,res,para+'(',open+1,close);
        }
        if(close<open){
            genrate(n,res,para+')',open,close+1);
        
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string para;
        int open=0,close=0;
        genrate(n,res,para,open,close);
        return res;
    }
};