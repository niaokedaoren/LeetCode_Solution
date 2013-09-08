class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<string> > collection;

		int wordSize = start.size();
		if (wordSize == 0)
			return collection;

		dict.insert(start);
		dict.insert(end);

		unordered_map<string, vector<string> > traces;
		vector<string> words;
		vector<vector<string> > layers(2, words);
		int cur = 0;
		int pre = 1;
		layers[cur].push_back(start);
		dict.erase(start);
		
		bool hasReached = false;
		unordered_set<string> curDeleted;
		while (layers[cur].size() > 0 && !hasReached) {
			cur = !cur;
			pre = !pre;
			layers[cur].clear();
			curDeleted.clear();

			for (auto itr = layers[pre].begin(); itr != layers[pre].end(); itr++) {
				string curWord = *itr;
				for (int n=0; n<wordSize; n++) {
					int temp = curWord[n] - 'a';
					for (int i=(temp+1)%26; i != temp; i = (i+1)%26) {
						curWord[n] = 'a' + i;
						if (dict.count(curWord) > 0) {
							if (curWord == end) {
								hasReached = true;
							}

							layers[cur].push_back(curWord);
							traces[curWord] = words;
							traces[curWord].push_back(*itr);
							dict.erase(curWord);
							curDeleted.insert(curWord);
						} else if (curDeleted.count(curWord) > 0) {
							traces[curWord].push_back(*itr);
						}
					}
					curWord[n] = 'a' + temp;
				}
			}
		}

		if (hasReached) {
			vector<string> path;
			path.push_back(end);
			constructPathes(collection, path, traces, end);
		}

		return collection;
    }

private:
	void constructPathes(vector<vector<string> > &collection, vector<string> &path, 
			unordered_map<string, vector<string> > &traces, const string &head) {

		if (traces.count(head) == 0) {
			reverse(path.begin(), path.end());
			collection.push_back(path);
			reverse(path.begin(), path.end());
			return;
		}

		vector<string> &words = traces[head];
		for (auto itr = words.begin(); itr != words.end(); itr++) {
			path.push_back(*itr);
			constructPathes(collection, path, traces, *itr);
			path.pop_back();
		}
	}
};
