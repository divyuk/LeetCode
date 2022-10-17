class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Concept of indegree and outdegree
        vector<int>data(n+1,0);
        for(auto i : trust){
            data[i[0]]--;
            data[i[1]]++;
        }
        for(int i = 1;i<=n ;i++){
            if(data[i]==n-1)
                return i;
        }
        return -1;
    }
};