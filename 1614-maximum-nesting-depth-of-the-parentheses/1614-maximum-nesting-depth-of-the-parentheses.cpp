class Solution {
public:
    int maxDepth(string s) {
        int result=0,depth=0;
        stack<int>stk;
        for(char c : s){
            if(c=='(') depth++;
            else if(c==')') depth--;
            result = max(result, depth);
        }
        return result;
    }
};