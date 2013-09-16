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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		bool lFlag, rFlag;
		int lBorder = findBorder(intervals, lFlag, newInterval.start);
		int rBorder = findBorder(intervals, rFlag, newInterval.end);

		if (lFlag && rFlag) {
			intervals[rBorder].start = intervals[lBorder].start;
			intervals.erase(intervals.begin()+lBorder, intervals.begin()+rBorder);
		} else if (!lFlag && rFlag) {
			intervals[rBorder].start = newInterval.start;
			intervals.erase(intervals.begin()+lBorder, intervals.begin()+rBorder);
		} else if (lFlag && !rFlag) {
			intervals[lBorder].end = newInterval.end;
			intervals.erase(intervals.begin()+lBorder+1, intervals.begin()+rBorder);
		} else {
			intervals.erase(intervals.begin()+lBorder, intervals.begin()+rBorder);
			intervals.insert(intervals.begin()+lBorder, newInterval);
		}

		return intervals;
    }

private:
	int findBorder(const vector<Interval> &intervals, bool &exist, int target) {
		int left = 0;
		int right = intervals.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (intervals[mid].start > target)
				right = mid - 1;
			else if (intervals[mid].end < target)
				left = mid + 1;
			else {
				exist = true;
				return mid;
			}
		}

		exist = false;
		return left;
	}
};
