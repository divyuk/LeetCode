class Solution {
private:
    int i=0; // Global variable

public:
    int calculate(string s) {
        int operand = 0;
        int result = 0; // For the on-going result
        int nextOperandSign = 1;  // 1 means positive, -1 means negative
        while (i < s.length()) {
            char ch = s[i++];

            if (ch == ' ' || isdigit(ch)) 
                operand = (ch == ' ') ? operand : 10 * operand + (ch - '0');
            else if (ch == '(') operand = calculate(s);
            else if (ch == ')') break; // Sub-expression we were evaluating has ended. Exit now...
            else {
                // If we're here, we just read the operator for the next operand/expression.
                // Evaluate the existing expression already read, reset operand, set sign for next incoming operand.
                result += nextOperandSign * operand;
                nextOperandSign = (ch == '+') ? 1 : -1;
                operand = 0;
            }
        }

        return result + (nextOperandSign * operand);
    }
};