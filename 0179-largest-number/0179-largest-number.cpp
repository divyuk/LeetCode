class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end() , [](const int &n1, const int &n2){
           string num1 = to_string(n1);
           string num2 = to_string(n2);
           return num1+num2 > num2+num1;
        });
        string result ="";
        for(int &i : nums) result+=to_string(i);
        if(result[0] == '0') return "0";
        return result;
    }
};