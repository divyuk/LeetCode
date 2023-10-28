class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>judge(n+1,0);
        for(auto x : trust){
            judge[x[0]]--;
            judge[x[1]]++;
        }
        for(int i =1;i<=n;i++){
            if(judge[i] == n-1)
                return i;
        }
        return -1;
    }
};