bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}

class Solution {
public:
    int candy(vector<int> &ratings) {
		int candyNum = 0;
		
		vector<pair<int, int> > vec;
		for (int i=0; i<ratings.size(); i++)
			vec.push_back(pair<int, int>(ratings[i], i));

		sort(vec.begin(), vec.end(), cmp);
		vector<int> state(ratings.size());
		for (int i=0; i<vec.size(); i++) {
			int index = vec[i].second;
			state[index] = 1;

			if (index > 0 && state[index-1] > 0) {
				if (ratings[index] > ratings[index-1])
					state[index] = state[index-1] + 1;
			}

			if (index < ratings.size()-1 && state[index+1] > 0) {
				if (ratings[index] > ratings[index+1] && 
						state[index] <= state[index+1])
					state[index] = state[index+1] + 1;
			}

			candyNum += state[index];
		}

		return candyNum;
    }
};
