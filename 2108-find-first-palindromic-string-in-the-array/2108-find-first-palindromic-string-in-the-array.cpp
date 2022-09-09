class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(auto i : words){
            int m = i.size();
            int left = 0;
            int right = m-1;
            bool flag = true;
            while(left<right){
                if(i[left]==i[right])
                    left++,right--;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return "";
    }
};