class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n,false);
        int highestCandyKid = *max_element(candies.begin(), candies.end());
        for(int i = 0; i< n;i++){
            int candyGiven = candies[i] + extraCandies;
            if(candyGiven >=highestCandyKid )
                result[i] = true;
        }
            
        
        return result;
    }
};