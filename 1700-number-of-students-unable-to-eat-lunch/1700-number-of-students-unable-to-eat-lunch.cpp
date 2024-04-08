class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int m = sandwiches.size();

        // Count of students who prefer circular (0) and square (1) sandwiches
        int count[2] = {0};

        for (int student : students) {
            count[student]++;
        }

        for (int i = 0; i < m; i++) {
            if (count[sandwiches[i]] > 0) {
                count[sandwiches[i]]--;
            } else {
                // No more students who prefer this type of sandwich
                return n - i;
            }
        }

        return 0;  // Everyone got their preferred sandwich
    }
};