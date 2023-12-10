#define ll long long
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> result;

        for (int i = 0; i < variables.size(); ++i) {
            ll ai = variables[i][0];
            ll bi = variables[i][1];
            ll ci = variables[i][2];
            ll mi = variables[i][3];

            ll formulaResult = (powerMod(powerMod(ai, bi, 10), ci, mi)) % mi;

            if (formulaResult == target) {
                result.push_back(i);
            }
        }

        return result;
    }

private:
    ll powerMod(ll base, ll exponent, ll modulus) {
        ll result = 1;
        base = base % modulus;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % modulus;
            }

            exponent = exponent >> 1;
            base = (base * base) % modulus;
        }

        return result;
    }
};
