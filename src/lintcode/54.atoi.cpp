/*
 * 54.atoi.cpp
 *
 *      Author: jerron
 *      https://www.lintcode.com/problem/78
 *      Implement function atoi to convert a string to an integer.
 */
#include "../utils/utils.h"

class Solution {
public:
	/**
	 * @param s: A string
	 * @return: An integer
	 */
	int atoi(string &s) {
		int res = 0, base = 10, maxi = INT_MAX / base, sign = 1, started = 0;
		for (auto c : s) {
			if (c >= '0' && c <= '9') {
				started = 1;
				if (res <= maxi) {
					res *= base;
					c -= '0';
					if (res < INT_MAX - c) {
						res += c;
						continue;
					}
				}
				return sign>0 ? INT_MAX : INT_MIN;
			} else if (started)
				break;
			else if (c != ' ') {
				started = 1;
				if (c == '-' )
					sign = -1;
				else if (c != '+' )
					break;
			}
		}
		return sign * res;
	}
};

#include <stdlib.h>     /* atoi */
	int main() {
		Solution s;
		vector<string> tests { "  +5","   +-1111", "2147483647", "-2147483648", "10",
				"1", "1.0", "123123123123123", };
		for (auto test : tests)
			if (s.atoi(test) != atoi(test.c_str())) {
				cout << "FAILED!" << s.atoi(test) << atoi(test.c_str());
				return 0;
			}

		cout << "SUCCEED!";
		return 0;
	}

