class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end()); // helps in choosing the smaller for minus and larger for plus
        int score = 0;
        int maxi = 0; //our answer
        int l = 0, r = n-1;
        while(l <= r) {
            if(power >= tokens[l]) { // taking away the power and adding to our score
                score++;
                power -= tokens[l];
                maxi = max(maxi, score);
                l++;
            }
            else if(power < tokens[l]) {
                if(score == 0) { // cannot do anything now
                    return maxi;
                }
                else{
                    power += tokens[r]; //if our power is less than a[l] we would like to recover the most out the tokens 
                    r--;
                    score--;
                }
            }
        }
        return maxi;
    }
};