class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int wordSize = start.size();
		if (wordSize == 0)
			return 0;

		dict.insert(start);
		dict.insert(end);

		int stepCount = 1;
		int cur = 0;
		int pre = 1;
		vector<string> words;
		vector<vector<string> > layers(2, words);
		layers[cur].push_back(start);
		dict.erase(start);

		while (!layers[cur].empty()) {
			cur = !cur;
			pre = !pre;
			stepCount++;
			layers[cur].clear();
			for (auto itr = layers[pre].begin(); itr != layers[pre].end(); itr++) {
				string curWord = *itr;
				for (int n=0; n<wordSize; n++) {
					int temp = curWord[n] - 'a';
					for (int i = (temp+1)%26; i != temp; i = (i+1)%26) {
						curWord[n] = 'a' + i;
						if (dict.count(curWord) > 0) {

							if (curWord == end)
								return stepCount;

							dict.erase(curWord);
							layers[cur].push_back(curWord);
						}
					}

					curWord[n] = 'a' + temp;
				}
			}
		}

		return 0;

    }
};
