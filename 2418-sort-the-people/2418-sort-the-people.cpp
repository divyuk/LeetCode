class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        vector<pair<int,string>>m;
        vector<string>n;
        for(int i=0;i<names.size() ; i++){
            m.push_back({heights[i] , names[i]});
        }
        sort(m.rbegin() , m.rend());
        for(auto it: m){
            n.push_back(it.second);
        }
        return n;
    }
};