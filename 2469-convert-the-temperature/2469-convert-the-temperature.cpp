class Solution {
public:
    vector<double> convertTemperature(double c) {
        vector<double> ans;
        double k = c + 273.15;
        double f = c*1.80 + 32.00;
        ans.push_back(k);
        ans.push_back(f);
        return ans;
    }
};