class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>data(1000000,0);
        for(auto x : edges){
            data[x[0]]++;
            data[x[1]]++;
        }
        for(int i=1;i<data.size();i++){
            if(data[i]>1)
                return i;
        }
        return 0;
    }
};