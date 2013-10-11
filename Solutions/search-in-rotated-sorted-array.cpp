class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		int left = 0;
		int right = n - 1;
		
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (A[left] < A[right]) {
				if (A[mid] < target)
					left = mid + 1;
				else if (A[mid] > target)
					right = mid - 1;
				else
					return mid;
			} else {
				if (A[mid] < target) {
					if (A[mid] <= A[right]) {
						if (target <= A[right])
							left = mid + 1;
						else
							right = mid - 1;
					} else {
						left = mid + 1;
					}
				} else if (A[mid] > target) {
					if (A[mid] >= A[left]) {
						if (target >= A[left])
							right = mid - 1;
						else
							left = mid + 1;
					} else {
						right = mid - 1;
					}
				} else
					return mid;
			}
		}

		return -1;
    }
};
