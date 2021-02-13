/*
 * 79. Longest Common Substring.cpp
 *
 *      Author: jerron
 *      https://www.lintcode.com/problem/79
 *      Given two strings, find the longest common substring.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(const string &A,const string &B) {
        int len=0;
        for(size_t i=0u,prev=i;i<B.length();++i)
            if((prev=A.find(B.substr(i-len,len+1),prev))!=string::npos)
                ++len;
            else
                prev=0;
        return len;
    }    
    int longestCommonSubstring2(const string &A, const string &B) {
        // write your code here
        vector<vector<int>> lcs{vector<int>(B.length(),0),vector<int>(B.length())};
        int largest = 0,prev=0,cur=1;
        for (auto i =0u; i < A.length(); i++,prev=cur,cur=1-prev) {
            largest=max(largest,lcs[cur][0] =A[i] == B[0]?1:0);
            for (auto j =1u; j < B.length(); j++) 
                if (A[i] == B[j])
                    largest=max(largest,lcs[cur][j] = lcs[prev][j - 1] + 1);
                else
                    lcs[cur][j]=0;
        }
        return largest;
    }
};
int main(){
    Solution s;
    if( s.longestCommonSubstring("ABCD","CBCE")==2&&
        s.longestCommonSubstring("ABCD","EACB")==1 )
        cout<<"SUCCEED!";
    else
        cout<<"FAILED!";
    return 0;
 }


