class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target > A[mid])
				left = mid + 1;
			else if (target < A[mid])
				right = mid - 1;
			else
				return mid;
		}

		return left;
    }
};
