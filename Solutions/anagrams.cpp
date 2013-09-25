class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<string> collection;
		unordered_map<string, vector<string> > dict;

		for (int i=0; i<strs.size(); i++) {
			string cur = strs[i];
			sort(cur.begin(), cur.end());

			if (dict.count(cur) > 0) {
				dict[cur].push_back(strs[i]);
			} else {
				vector<string> vec(1, strs[i]);
				dict[cur] = vec;
			}
		}

		for (auto itr = dict.begin(); itr != dict.end(); itr++) {
			if (itr->second.size() > 1) {
				collection.insert(collection.end(), 
						itr->second.begin(), itr->second.end());
			}
		}

		return collection;
    }
};
