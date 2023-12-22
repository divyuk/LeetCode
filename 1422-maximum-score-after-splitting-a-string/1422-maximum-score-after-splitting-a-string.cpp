class Solution {
public:
    int maxScore(string s) {
        int ro=0,l0=0,score=0;
        for(char c : s) if(c=='1') ro++;
        for(int i =0 ; i<s.length()-1;i++){
            if(s[i]=='0') l0++;
            else ro--;
            score=max(score , l0+ro);
        }
        return score;
    }
};