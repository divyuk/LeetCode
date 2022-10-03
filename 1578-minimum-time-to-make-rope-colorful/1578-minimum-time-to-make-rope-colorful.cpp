class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans=0,k=0;
        for(int i=0,j=1;j<n;i++,j++){
            if(colors[i] == colors[i+1]){
                k = neededTime[i]<neededTime[i+1]?i:i+1;
                ans+=neededTime[k];
                if(k!=0){
                    colors[k] = colors[k-1];
                    neededTime[k] = neededTime[k-1];
                }
            }
        }
        return ans;
    }
};