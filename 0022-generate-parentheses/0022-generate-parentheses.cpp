class Solution {
public:
    
    void generator(int n, vector<string>&para, string p, int open, int close){
        
        // base case
        if( open == n and close == n){
            para.push_back(p);
            return;
        }
        
        if(open<n)
            generator(n, para, p+'(', open+1, close);
        if(close<open)
            generator(n, para, p+')' , open, close+1);
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string>para;
        generator(n,para,"", 0, 0);
        return para;
    }
};