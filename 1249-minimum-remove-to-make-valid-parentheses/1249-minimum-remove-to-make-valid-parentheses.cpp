class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        vector<int> removal;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if(s[i] == ')') {
                if(!stk.empty()) {
                    stk.pop();
                } else {
                    removal.push_back(i);
                }
            }
        }
        
        while(!stk.empty()) {
            removal.push_back(stk.top());
            stk.pop();
        }
        
        string result = "";
        for(int i = 0; i < n; i++) {
            if(find(removal.begin(), removal.end(), i) == removal.end()) {
                result += s[i];
            }
        }
        
        return result;
    }
};
