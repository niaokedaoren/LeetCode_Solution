class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		unordered_map<int, int> counter;
		for (int i=0; i<n; i++) {
			if (counter.count(A[i]) == 0)
				counter[A[i]] = 1;
			else
				counter[A[i]]++;
		}

		for (auto itr = counter.begin(); itr != counter.end(); itr++)
			if (itr->second == 1)
				return itr->first;

		return 0;
    }
};
