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
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(const string &source,const string &target) {
        int szSource=source.length(),szTarget=target.length();
        if (!szTarget)
            return 0;
        vector<int> lookup(szTarget);
        lookup[0]=-1;
        for(auto i=1,j=0;i<szTarget;++i){
            if (target[i]==target[j])
                lookup[i]=lookup[j++];
            else{
                lookup[i]=j;
                j=0;
            }
        }        
        for(auto i=0,j=i;i<(int)szSource;++i){
            for(;j>=0 && source[i]!=target[j];)
                j=lookup[j];
            if(++j>=szTarget)
                return i+1-szTarget;
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<pair<string,string>> tests={
        {"a","a"},
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


