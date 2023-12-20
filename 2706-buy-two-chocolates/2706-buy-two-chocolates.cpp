class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin() , prices.end());
        int cnt =0, ans=money;
        for(int i : prices){
            if(i<=money and money>0){
                money=money-i;
                cnt++;
                
            }
            if(cnt==2) break;
        }
        if(cnt==2 and money>=0) return money;
        return ans;
    }
};