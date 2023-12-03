#define ll long long
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        ll mp = 0;
        ll ca = 0;

        for (int coin : coins) {
            if (coin > mp + 1) {
                while (mp + 1 < coin) {
                    mp += mp + 1;
                    ca++;
                }
            }
            mp += coin;
        }

        while (mp < target) {
            mp += mp + 1;
            ca++;
        }

        return ca;
    }
};