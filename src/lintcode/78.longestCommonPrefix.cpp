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
        auto n=strs.size();
        vector<decltype(strs.front().c_str())> ps(n);
        for(auto i=0u;i<n;++i)
            ps[i]=strs[i].c_str();
        for(;n>1;++ps[0])
            for(auto i=1u;i<n;++i)
                if(*(ps[i]++)!=*ps[0])
                    return strs.front().substr(0,ps[0]-strs.front().c_str());
        return n?strs.front():"";
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


