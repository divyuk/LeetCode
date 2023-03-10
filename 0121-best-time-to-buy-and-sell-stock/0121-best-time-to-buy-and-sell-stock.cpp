class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int buy = prices[0];
        int sell = 0;
        int diff = 0;
        int m = buy;
        for(int i = 1 ; i<n ; i++){
            if(buy > prices[i]){
                buy = prices[i];
                sell = 0;
            }
            else
                sell = prices[i];
            
            diff = sell - m;
            ans = max(ans , diff);
            m = min(m , buy);
        }
        return ans;
    }
};