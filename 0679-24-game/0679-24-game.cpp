class Solution {
private:
    vector<double>getValidOperations(double a , double b){
        vector<double>validOperations;
        validOperations.push_back(a+b);
        validOperations.push_back(a-b);
        validOperations.push_back(b-a);
        validOperations.push_back(a*b);
        if(abs(b) > FLT_EPSILON)
            validOperations.push_back(a/b);
        if(abs(a) > FLT_EPSILON)
            validOperations.push_back(b/a);
        
        return validOperations;
    }
    bool isPossible(vector<double>&arr){
        int n = arr.size();
        
        // base case
        if(n==1) return abs(24.0 - arr[0]) <=FLT_EPSILON;
        
        for(int fn = 0;fn<n;fn++){
            for(int sn =0;sn<n;sn++){
                if(sn==fn) continue;
                double firstNumber = arr[fn];
                double secondNumber = arr[sn];
                
                vector<double>validOperations = getValidOperations(firstNumber, secondNumber);
                vector<double>operatedArray;
                
                for(double validOperation: validOperations){
                    operatedArray.clear();
                    operatedArray.push_back(validOperation);
                    
                    for(int i =0;i<n;i++){
                        if(i==fn or i ==sn) continue;
                        operatedArray.push_back(arr[i]);
                    }
                    if(isPossible(operatedArray)) return true;
                }
            }
        }
        return false;
        
    }
    
    
public:
    bool judgePoint24(vector<int>& cards) {
        // Since we will operating on the array some double resulting operations hence making it double arr
        
        vector<double>arr(cards.begin() , cards.end());
        
        return isPossible(arr);
    }
};