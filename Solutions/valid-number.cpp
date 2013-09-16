class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (s == NULL || *s == '\0')
			return false;

		bool inSpace = true;
		bool hasPoint = false;
		bool hasDigit = false;
		bool validInt = true;

		while (*s) {
			switch (*s) {
				case ' ':
					if (inSpace == false) {
						while (*s) {
							if (*s != ' ')
								return false;
							s++;
						}
						s--;
					}
					break;
				case '.':
					if (hasPoint)
						return false;
					hasPoint = true;
					inSpace = false;
					break;
				case '+':
				case '-':
					if (inSpace == false)
						return false;
					inSpace = false;
					break;
				case 'e':
				case 'E':
					return hasDigit && isInt(++s);
				default:
					if (isdigit(*s)) {
						inSpace = false;
						hasDigit = true;
					} else {
						return false;
					}
			}

			s++;
		}

		return hasDigit;
    }

private:
	bool isInt(const char *s) {
		if (s == NULL || *s == '\0')
			return false;

		bool hasSign = false;
		bool hasDigit = false;

		while (*s) {
			if (*s == '+' || *s == '-') {
				if (hasDigit || hasSign)
					return false;
				hasSign = true;
			} else if (isdigit(*s)) {
				hasDigit = true;
			} else if (*s == ' ') {
				while (*s) {
					if (*s != ' ')
						return false;
					s++;
				}
				s--;
			} else
				return false;

			s++;
		}

		return hasDigit;

	}
};
