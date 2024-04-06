class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        unordered_set<int> removal;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if(s[i] == ')') {
                if(!stk.empty()) {
                    stk.pop();
                } else {
                    removal.insert(i);
                }
            }
        }
        
        while(!stk.empty()) {
            removal.insert(stk.top());
            stk.pop();
        }
        
        string result = "";
        for(int i = 0; i < n; i++) {
            if(removal.find(i) == removal.end()) result += s[i];
        
        }
        
        return result;
    }
};
