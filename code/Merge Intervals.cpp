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

    static bool compareStart(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), Solution::compareStart);
        vector<Interval> res;
        int slow = 0;

        while(slow < intervals.size()) {
            int fast = slow + 1;
            while(fast < intervals.size() && intervals[fast].start <= intervals[fast-1].end) {
                if(intervals[fast].end <= intervals[fast-1].end) {
                    intervals[fast].end = intervals[fast-1].end;
                }
                fast++;
            }

            Interval tmp(intervals[slow].start, intervals[fast-1].end);
            res.push_back(tmp);
            slow = fast;
        }
        
        return res;
    }
};

int main() {


}