class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count =0;
        for(auto i : items){
            if(ruleKey=="type" and ruleValue == i[0])
                count++;
            else if(ruleKey=="color" and ruleValue == i[1])
                count++;
            else if(ruleKey=="name" and ruleValue == i[2])
                count++;
        }
            return count;
    }
};