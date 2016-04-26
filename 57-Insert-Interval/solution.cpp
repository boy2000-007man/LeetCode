/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty())
            intervals.push_back(newInterval);
        else {
            int ls, le;
            for (int &l = ls = 0, r = intervals.size() - 1; l < r; )
                if (intervals[l + r >> 1].start <= newInterval.start && newInterval.start <= intervals[l + r >> 1].end)
                    l = r = l + r >> 1;
                else if (newInterval.start < intervals[l + r >> 1].start)
                    r = l + r >> 1;
                else
                    l = (l + r >> 1) + 1;
            if (intervals[ls].end < newInterval.start)
                ls++;
            for (int &l = le = 0, r = intervals.size() - 1; l < r; )
                if (intervals[l + r >> 1].start <= newInterval.end && newInterval.end <= intervals[l + r >> 1].end)
                    l = r = l + r >> 1;
                else if (newInterval.end < intervals[l + r >> 1].start)
                    r = l + r >> 1;
                else
                    l = (l + r >> 1) + 1;
            if (newInterval.end < intervals[le].start)
                le--;
            if (le < ls) {
                intervals.push_back(newInterval);
                for (int i = intervals.size() - 2; ls <= i; i--)
                    swap(intervals[i], intervals[i + 1]);
            } else {
                intervals[ls].start = min(intervals[ls].start, newInterval.start);
                intervals[ls].end = max(intervals[le].end, newInterval.end);
                if (ls < le) {
                    for (int i = ls + 1; i + le - ls < intervals.size(); i++)
                        swap(intervals[i], intervals[i + le - ls]);
                    intervals.resize(intervals.size() - (le - ls));
                }
            }
        }
        return intervals;
    }
};