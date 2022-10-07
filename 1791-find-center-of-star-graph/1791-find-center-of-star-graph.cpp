class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a =0,b=0;
        a = edges[0][0];
        b = edges[0][1];
        // if(edges[1][0] == a )
        //     return a;
        // else if(edges[1][1] == a)
        //     return a;
        // return b;
        int k = edges[1][0] == a or edges[1][1] == a ? a : b;
        return k;
    }
};