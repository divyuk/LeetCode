class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count=0;
        while(left<=right){
            
            string w = words[left];
            char c = w[0];
            char c2 = w[w.size()-1];
            if((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') and (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u')) 
               count++;
            left++;
        }
         return count;
    }
};