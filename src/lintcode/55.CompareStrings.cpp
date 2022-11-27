/*
 * 55. Compare Strings.cpp
 *
 *      Author: jerron
 *      https://www.lintcode.com/problem/55
 *      Compare two strings A and B, determine whether A contains all of the characters in B.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(const string &A,const string &B) {
        vector<int> S('Z'-'A'+1,0);
        for(auto c:A)
            ++S[c-'A'];
        for(auto c:B)
            if(--S[c-'A']<0)
                return false;
        return true;           
    }
};

int main(){
    Solution s;
      Solution s;
  
  vector<pair<vector<string>, vector<int>>> tests = {
       {{"abab","aa"},{1}},
     {{"A","B"},{0}},
      {{"A","AZ"}{0}},
      {{"AZ","BZ"}{0}},
  };
    if( s.compareStrings("ABCD","ACD") )
        cout<<"SUCCEED!";
    else
        cout<<"FAILED!";
    return 0;
}


