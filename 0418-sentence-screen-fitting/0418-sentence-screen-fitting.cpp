class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // Combine all words into a single string with spaces in between
        string combined = "";
        for (const string& word : sentence) {
            combined += word + " ";
        }
        
        int len = combined.size();
        int count = 0;
        
        for (int i = 0; i < rows; ++i) {
            count += cols;
            // If the current position ends with a space, move to the next position
            if (combined[count % len] == ' ') {
                count++;
            } else {
                // Otherwise, move backward to the beginning of the current word
                while (count > 0 && combined[(count - 1) % len] != ' ') {
                    count--;
                }
            }
        }
        
        // Calculate the number of times the sentence can fit
        return count / len;
    }
};
