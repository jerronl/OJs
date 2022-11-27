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
        vector<int> v('Z'-'A'+1,0);
        for(auto c:A)
            v[c-'A']++;
        for(auto c:b)
            if(!(v[c-'A']--))
                return false;
        return true;
};

int main(){
    Solution s;
    if( s.compareStrings("ABCD","ACD") )
        cout<<"SUCCEED!";
    else
        cout<<"FAILED!";
    return 0;
}


