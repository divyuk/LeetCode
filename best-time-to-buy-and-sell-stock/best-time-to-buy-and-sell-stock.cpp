class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We want to buy at cheap and sell at max
        int buy = prices[0];
        int sell=0;
        int length = prices.size();
        for(int price = 1 ; price < length ; price++){
            buy = min(buy, prices[price]);
            sell = max( sell , prices[price] - buy);
        }
        return sell;
    }
};