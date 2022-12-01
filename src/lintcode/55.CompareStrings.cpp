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
    vector<int> S('Z'-'A'+1, 0);//MAIN CHANGE
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
  vector<pair<vector<string>, vector<int>>> tests = {
      {{"abab", "aa"}, {1}},
      {{"A", "B"}, {0}},
      {{"AZ", "AZ"}, {1}},//FAILED CASE ON UNEDITED VERSION
      {{"AZ", "BZ"}, {0}},
      {{"PQRTZ","RSTUV"},{0}}

  };
  for (auto test : tests) {
    auto tmp = test.first;
    if (s.compareStrings(tmp[0], tmp[1]) != test.second[0]) {
      cout << "FAILED!" << endl;
      return 0;
    }
  }
   //BETTER TESTCASES
  cout << "SUCCEED!";
  return 0;
}
