class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (x <= 0)
			return 0;

		int left = 0;
		int right = 15;
		while (left < right) {
			int mid = (left + right) / 2;
			int cur = 1 << mid;
			cur = cur * cur;
			if (x < cur)
				right = mid - 1;
			else if (x > cur)
				left = mid + 1;
			else
				break;
		}

		float root = 1 << left;
		while (true) {
			float next = (x / root + root) / 2.0;

			if ((int)root == (int)next) {
				int curRoot = (int)next;
				int temp = curRoot * curRoot;
				if (temp < 0 || temp > x)
					return curRoot - 1;
				else
					return curRoot;
			}

			root = next;
		}
    }
};
