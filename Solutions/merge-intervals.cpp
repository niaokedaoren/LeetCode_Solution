/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a, const Interval &b) {
	return a.start <= b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (intervals.size() == 0 || intervals.size() == 1)
			return intervals;

		sort(intervals.begin(), intervals.end(), cmp);
		int pivot = 0;
		for (int i=1; i<intervals.size(); i++) {
			if (intervals[pivot].end < intervals[i].start) {
				pivot++;
				intervals[pivot].start = intervals[i].start;
				intervals[pivot].end = intervals[i].end;
			} else {
				if (intervals[i].end > intervals[pivot].end)
					intervals[pivot].end = intervals[i].end;
			}
		}

		intervals.erase(intervals.begin()+pivot+1, intervals.end());

		return intervals;
    }
};
