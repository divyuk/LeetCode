class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numbers){
        sort(numbers.begin() , numbers.end());
        vector<vector<int>>ans;
        for(int k = 0 ; k < numbers.size() ; k++){
            if(k>0 and numbers[k] == numbers[k-1])
                continue;
            int i = k+1, j = numbers.size()-1;
            while (i<j)
            {
                vector<int>t;
                int sum = numbers[i] + numbers[j] + numbers[k];
                if( sum == 0){
                    t.push_back(numbers[k]);
                    t.push_back(numbers[i]);
                    t.push_back(numbers[j]);
                    ans.push_back(t);
                    i++;
                    while (numbers[i]==numbers[i-1] and i<j)
                        i++;
                    
                }
                else if(sum>0)
                    j--;
                else
                    i++;
            }
        }
        return ans;
    }
};