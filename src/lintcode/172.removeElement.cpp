/*
 * 172.removeElement.cpp
 *      https://www.lintcode.com/problem/172
 *      Given an array and a value, remove all occurrences of that value in place and return the new length.
 */
#include "../utils/utils.h"

class Solution {
public:
	/*
	 * @param A: A list of integers
	 * @param elem: An integer
	 * @return: The new length after remove
	 */
	int removeElement(vector<int> &A, int elem) {
		auto i = -1;
		for (auto a : A)
			if (a != elem)
				A[++i] = a;
		return ++i;
	}
};

int main() {
	Solution s;
	vector<pair<pair<vector<int>,int>, vector<int>>> tests = {
			{ {{},0 }, { } },
			{{ {0,4,4,0,0,2,4,4},4 }, { 0,0,0,2} }
	};
	for (auto test : tests) {
		auto tmp = test.first.first;
		tmp.resize(s.removeElement(tmp,test.first.second));
		if (tmp != test.second) {
			cout << "FAILED!" << test << tmp;
			return 0;
		}
	}
	cout << "SUCCEED!";
	return 0;
}

