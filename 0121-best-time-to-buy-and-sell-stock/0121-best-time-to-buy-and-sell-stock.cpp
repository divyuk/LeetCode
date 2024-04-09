class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We want to buy at cheap and sell at max
        int buy = prices[0];
        int sell=0;
        int length = prices.size();
        for(int i = 1 ; i < length ; i++){
            buy = min(buy, prices[i]);
            sell = max( sell , prices[i] - buy);
        }
        return sell;
    }
};