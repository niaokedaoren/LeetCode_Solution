class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		if (s.size() <= 1)
			return 0;

		stack<pair<char, int> > state;
		state.push(make_pair('#', -1));
		int n = 0;
		while (n < s.size()) {
			if (s[n] == '(')
				state.push(make_pair('(', n));
			else {
				pair<char, int> &top = state.top();
				if (top.first == '(')
					state.pop();
				else
					state.push(make_pair(')', n));
			}

			n++;
		}

		int end = s.size();
		int max = 0;
		while (!state.empty()) {
			pair<char, int> &top = state.top();
			int temp = end - top.second - 1;
			end = top.second;
			if (max < temp)
				max = temp;
			state.pop();
		}

		return max;
    }
};
