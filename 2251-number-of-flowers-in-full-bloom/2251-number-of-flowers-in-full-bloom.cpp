class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        vector<int>start(m);
        vector<int>end(m);
        vector<int>result(n);
        for(int i =0 ;i<m;i++){
            int s = flowers[i][0];
            int e = flowers[i][1];
            start[i] = s;
            end[i]   = e;
        }
        sort(start.begin(), start.end());
        sort(end.begin() , end.end());
        
        for(int i =0 ;i<n;i++){
            int time = people[i];
            int bloomFlower = upper_bound(start.begin(),start.end(), time) - start.begin();
            int diedFlower  = lower_bound(end.begin(),end.end(), time) - end.begin();
            result[i] = bloomFlower - diedFlower;
        }
        return result;
    }
};