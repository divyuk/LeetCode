/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> merged;
        for (auto& intervals : schedule) {
            merged.insert(merged.end(), intervals.begin(), intervals.end());
        }
        sort(merged.begin(), merged.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        vector<Interval> result;
        int prevEnd = merged[0].end;
        for (int i = 1; i < merged.size(); ++i) {
            if (merged[i].start > prevEnd) {
                result.emplace_back(prevEnd, merged[i].start);
            }
            prevEnd = max(prevEnd, merged[i].end);
        }
        return result;
    }
};