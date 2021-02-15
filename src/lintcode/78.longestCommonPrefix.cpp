/*
 * 79. Longest Common Substring.cpp
 *
 *      Author: jerron
 *      https://www.lintcode.com/problem/78
 *      Given k strings, find the longest common prefix (LCP).
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(const vector<string> &strs) {
        if(!strs.size())
            return "";
        for(auto len=0;len<strs.front().length();++len)
            for(auto i=1u;i<strs.size();++i)
                if(strs[i][len]!=strs.front()[len])
                    return strs.front().substr(0,len);
        return strs.front();
    }
};
int main(){
    Solution s;
    vector<pair<vector<string>,string>> tests{
        {{},""},
        {{ "ABCD", "ABEF", "ACEF"},"A"},
        {{"ABCDEFG", "ABCEFG" , "ABCEFA"},"ABC"}
    };
    for(auto test:tests)
        if (s.longestCommonPrefix(test.first)!=test.second){
            cout<<"FAILED!";
            return 0;
        }
    
    cout<<"SUCCEED!";
    return 0;
 }


