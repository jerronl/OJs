/*
* 55.Compare-Strings.cpp
* Author:jerron
* https://lintcode.com/problem/55
* Compare two strings A and B, determine whether A contains all characters in B
*/
#include "util.h"
class Solution {
public:
  /**
   * @param A: A string
   * @param B: A string
   * @return: if string A contains all of the characters in B return true else
   * return false
   */
  bool compareStrings(const string &A, const string &B) {
    vector<int> S('Z'-'A'+1, 0);
    for (auto c : A)
      ++S[c - 'A'];
    for (auto c : B)
      if (--S[c - 'A'] < 0)
        return false;
    return true;
  }
};

int main() {
  Solution s;
  vector<pair<vector<string>, bool>> tests = {
      {{"abab", "aa"}, 1},
      {{"A", "B"}, 0},
      {{"AZ", "AZ"}, 1},
      {{"AZ", "BZ"}, 0},
      {{"PQRTZ","RSTUV"},0}

  };
  for (auto test : tests) {
    auto tmp = test.first;
    if (s.compareStrings(tmp[0], tmp[1]) != test.second) {
      cout << "FAILED!" << endl;
      return 0;
    }
  }
  cout << "SUCCEED!";
  return 0;
}
