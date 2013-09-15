class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	vector<string> lines;
		
		vector<string> wordsInLine;
		int lineLen = 0;
		for (int i=0; i<words.size(); i++) {
			if (lineLen + words[i].size() + wordsInLine.size() > L) {
				string line = "";
				int wordNum = wordsInLine.size();
				if (wordNum == 1) {
					line += wordsInLine[0];
					line.append(L-lineLen, ' ');
				} else {
					int remain = L - lineLen;
					int spaceNum = remain / (wordNum - 1);
					line += wordsInLine[0];
					for (int k=1; k<wordNum; k++) {
						line.append(spaceNum, ' ');
						if (k <= remain % (wordNum - 1))
							line.append(1, ' ');
						line += wordsInLine[k];
					}
				}

				lines.push_back(line);
				lineLen = 0;
				wordsInLine.clear();
			}

			wordsInLine.push_back(words[i]);
			lineLen += words[i].size();
		}

		if (wordsInLine.size() > 0) {
			string line = wordsInLine[0];
			for (int i=1; i<wordsInLine.size(); i++) {
				line.push_back(' ');
				line += wordsInLine[i];
			}

			line.append(L-lineLen-wordsInLine.size()+1, ' ');
			lines.push_back(line);
		}

		return lines;
    }
};
