class Solution {
public:
    string countOfAtoms(string formula) {
        // Recursively parse the formula
        unordered_map<string, int> finalMap = parseFormula(formula);

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }

    // Recursively parse the formula
    unordered_map<string, int> parseFormula(string& formula) {
        // Local variable
        unordered_map<string, int> currMap;

        // Iterate until the right parenthesis or end of the formula
        while (index < formula.length() && formula[index] != ')') {
            // If left parenthesis, do recursion
            if (formula[index] == '(') {
                index++;
                unordered_map<string, int> nestedMap = parseFormula(formula);
                for (auto& [atom, count] : nestedMap) {
                    currMap[atom] += count;
                }
            }

            // Otherwise, it should be UPPERCASE LETTER
            // Extract the atom and count in one go.
            else {
                string currAtom;
                currAtom += formula[index];
                index++;
                while (index < formula.length() && islower(formula[index])) {
                    currAtom += formula[index];
                    index++;
                }

                string currCount;
                while (index < formula.length() && isdigit(formula[index])) {
                    currCount += formula[index];
                    index++;
                }

                if (currCount.empty()) {
                    currMap[currAtom] += 1;
                } else {
                    currMap[currAtom] += stoi(currCount);
                }
            }
        }

        // If the right parenthesis, extract the multiplier
        // and multiply the count of atoms in the curr_map
        index++;
        string multiplier;
        while (index < formula.length() && isdigit(formula[index])) {
            multiplier += formula[index];
            index++;
        }
        if (!multiplier.empty()) {
            int mult = stoi(multiplier);
            for (auto& [atom, count] : currMap) {
                currMap[atom] = count * mult;
            }
        }

        return currMap;
    }

private:
    // Global variable
    int index = 0;
};