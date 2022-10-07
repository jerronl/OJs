/*
 * 13. strStr.cpp
 *
 *      Author: jerron
 *      https://www.lintcode.com/problem/13
 *      For a given source string and a target string, you should output the first index(from 0) of target string in the source string.If the target does not exist in source, just return -1.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(const string &source,const string &target) {
        vector<int> lookup{-1};
        int i=0,j=0,szTarget;
        if (target[0])
            for(i=1;target[i];++i)
                if (target[i]==target[j])
                    lookup.push_back(lookup[j++]);
                else{
                    lookup.push_back(j);
                    j=0;
                }
        for(szTarget=i,i=0,j=i;source[i]&&j<szTarget;++i,++j)
            for(;j>=0 && source[i]!=target[j];)
                j=lookup[j];
        return j<szTarget?-1:i-j;    
    }

};

int main(){
    Solution s;
    vector<pair<string,string>> tests={
        {"",""},
        {"","a"},
        {"a",""},
        {"a","a"},
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaab"},
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaab","aaaaaab"},
        {"dsfsf",""},
        {"abcabcabdids","abcabd"},
        {"source","target"},
        {"abcdabcdefg","bcd"}
    };
    for(auto test:tests)
        if ((test.first.find(test.second)!=(size_t)s.strStr(test.first,test.second))){
            cout<<"FAILED!"<<test<<test.first.find(test.second)<<s.strStr(test.first,test.second)<<endl;
            return 0;
        }
    
    cout<<"SUCCEED!";
    return 0;
 }


