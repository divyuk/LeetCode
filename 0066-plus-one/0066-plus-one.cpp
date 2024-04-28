class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int carry = 1;
        for(int i = n-1 ; i>=0; i--){
            int add = digits[i] + carry;
            int sum = add %10;
            carry = add/10;
            ans.push_back(sum);
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};