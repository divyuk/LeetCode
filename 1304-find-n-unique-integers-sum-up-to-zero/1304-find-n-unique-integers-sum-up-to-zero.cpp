class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n==2){
            ans.push_back(-1);
            ans.push_back(1);
            return ans;
        }
        for(int i = 1;i<n;i++)
            ans.push_back(i);
        long long sum = ((n-1)*(n))/2;
        ans.push_back(-sum);
        return ans;
    }
};