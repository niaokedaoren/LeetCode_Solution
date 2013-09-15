class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	if (path.size() == 0 || path[0] != '/')
			return "";

		vector<string> track;
		int begin = 0; 
		path.push_back('/');
		for (int i=1; i<path.size(); i++) {
			if (path[i] != '/')
				continue;

			int len =  i - begin - 1;
			if (len > 0) {
				string cur = path.substr(begin+1, len);
				if (cur == "..") {
					if (track.size() > 0)
						track.pop_back();
				} else if (cur != ".") {
					track.push_back(cur);
				}
			}

			begin = i;
		}

		if (track.size() > 0) {
			string newPath = "";
			for (int i=0; i<track.size(); i++) {
				newPath.push_back('/');
				newPath += track[i];
			}

			return newPath;

		} else {
			return "/";
		}
    }
};
