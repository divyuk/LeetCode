class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charArray(26, 0);

        for (int i = 0; i < chars.size(); i++)
            charArray[chars[i] - 'a']++;

        int counter = 0;
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            vector<int> tempArray = charArray;  // Create a copy of the original array

            bool flag = true;
            for (int j = 0; j < w.size(); j++) {
                if (tempArray[w[j] - 'a'] != 0)
                    tempArray[w[j] - 'a']--;
                else {
                    flag = false;
                    break;
                }
            }

            if (flag)
                counter += w.size();
        }
        return counter;
    }
};
