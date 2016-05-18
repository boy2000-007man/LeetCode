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
    static bool cmp(const Interval &i1, const Interval &i2) {
        return make_pair(i1.start, i1.end) < make_pair(i2.start, i2.end);
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int len = 0;
        for (auto i: intervals)
            if (!len || intervals[len - 1].end < i.start)
                intervals[len++] = i;
            else
                intervals[len - 1].end = max(intervals[len - 1].end, i.end);
        intervals.resize(len);
        return intervals;
    }
};