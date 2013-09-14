class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (height.size() == 0)
			return 0;

		stack<int> incSeq;
		incSeq.push(-1);
		incSeq.push(0);
		int maxArea = 0;
		height.push_back(-1);

		for (int i=1; i<height.size(); i++) {
			int top = incSeq.top();
			while (incSeq.size() > 1 && height[i] <= height[top]) {
				incSeq.pop();
				int curArea = (i-incSeq.top()-1) * height[top];
				if (curArea > maxArea)
					maxArea = curArea;
				top = incSeq.top();
			}

			incSeq.push(i);
		}

		return maxArea;
    }
};
