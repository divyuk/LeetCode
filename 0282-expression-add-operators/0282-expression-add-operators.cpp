class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string expr;
        backtrack(result, expr, num, target, 0, 0, 0);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& expr, const string& num, int target,
                   int start, long long currVal, long long prevNum) {
        if (start == num.size()) {
            if (currVal == target) {
                result.push_back(expr);
            }
            return;
        }

        for (int i = start; i < num.size(); ++i) {
            // Handle cases where we have a number with leading zero
            if (i != start && num[start] == '0') break;
            
            string currStr = num.substr(start, i - start + 1);
            long long curr = stoll(currStr);

            if (start == 0) {
                expr += currStr; // expression banao
                backtrack(result, expr, num, target, i + 1, curr, curr);
                expr.erase(expr.size() - currStr.size());
            } else {
                // Addition
                expr += "+" + currStr;
                backtrack(result, expr, num, target, i + 1, currVal + curr, curr);
                expr.erase(expr.size() - 1 - currStr.size()); // current String se hatao

                // Subtraction
                expr += "-" + currStr;
                backtrack(result, expr, num, target, i + 1, currVal - curr, -curr);
                expr.erase(expr.size() - 1 - currStr.size());

                // Multiplication
                expr += "*" + currStr;
                backtrack(result, expr, num, target, i + 1, currVal - prevNum + prevNum * curr, prevNum * curr);
                expr.erase(expr.size() - 1 - currStr.size());
                
                
            }
        }
    }
};


// in case of multiplication
// 7 + 3* 2 ==== 10 -3 + 3 *2 ==?prevNum +3