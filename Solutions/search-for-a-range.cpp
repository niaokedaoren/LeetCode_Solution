class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		int left = 0;
		int right = n - 1;
		int mid;

		while (left <= right) {
			mid = left + (right - left) / 2;
			if (target > A[mid])
				left = mid + 1;
			else if (target < A[mid])
				right = mid - 1;
			else
				break;
		}

		vector<int> range(2, -1);
		if (left > right)
			return range;

		//search left border
		range[0] = mid;
		int lEnd = left;
		int rEnd = mid - 1;
		while (lEnd <= rEnd) {
			int m = lEnd + (rEnd - lEnd) / 2;
			if (A[m] < target)
				lEnd = m + 1;
			else {
				range[0] = m;
				rEnd = m - 1;
			}
		}

		// search right border
		range[1] = mid;
		lEnd = mid + 1;
		rEnd = right;
		while (lEnd <= rEnd) {
			int m = lEnd + (rEnd - lEnd) / 2;
			if (A[m] > target)
				rEnd = m - 1;
			else {
				range[1] = m;
				lEnd = m + 1;
			}
		}

		return range;
    }
};
