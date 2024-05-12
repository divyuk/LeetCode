class Solution {
public:
    string nextClosestTime(string time) {
        string hour = time.substr(0, 2);
        string minute = time.substr(3);
        
        // Generate all possible 2 digit values
        // There are at most 16 sorted values here
        // set<char> nums(hour.begin(), hour.end());
        // nums.insert(minute.begin(), minute.end());
        string nums(hour + minute);
        sort(nums.begin(), nums.end());
        set<string> two_digit_values;
        for (char a : nums) {
            for (char b : nums) {
                two_digit_values.insert(string(1, a) + string(1, b));
            }
        }

        // Check if the next valid minute is within the hour
        auto it = two_digit_values.find(minute);
        if (next(it) != two_digit_values.end() && *next(it) < "60") {
            return hour + ":" + *next(it);
        }

        // Check if the next valid hour is within the day
        it = two_digit_values.find(hour);
        if (next(it) != two_digit_values.end() && *next(it) < "24") {
            return *next(it) + ":" + *two_digit_values.begin();
        }
        
        // Return the earliest time of the next day
        return *two_digit_values.begin() + ":" + *two_digit_values.begin();
    }
};
