class Solution {
private:
    vector<string> neighbors(const string& code) {
        vector<string> result;
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
    vector<string> children(string lock){
        vector<string> res;
        for(int i =0; i< 4; i++){
            char digit =((lock[i] - '0') + 1) % 10 + '0';
            res.push_back( lock.substr(0,i) + digit + lock.substr(i+1) );
            digit = ((lock[i] - '0' ) -1 + 10) % 10 + '0';
            res.push_back( lock.substr(0,i)  + digit + lock.substr(i+1) );
        }
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q; // [locks, turns]
        q.push({"0000" , 0});
        unordered_set<string>visited(deadends.begin() , deadends.end());
        if(visited.find("0000") != visited.end()) return -1;
        
        while(!q.empty()){
            auto [lock, turns] = q.front();
            q.pop();
            if(lock == target) return turns;
            for(auto child : children(lock)){
             
                if(visited.find(child)==visited.end()){
                    visited.insert(child);
                    q.push({child,turns+1});
                }
            }
        }
        return -1;
    }
};