class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto it : num){
            while(!st.empty() && k > 0 && st.top() > it){
                st.pop();
                k--;
            }
            st.push(it);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string s;
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        int idx = 0;
        while(idx < s.size() && s[idx] == '0'){
            idx++;
        }
        s = s.substr(idx);
        return (s.size() == 0) ? "0" : s;
    }
};