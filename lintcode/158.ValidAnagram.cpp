/*
 * 158.Valid Anagram.cpp
 *
 *      Author: jerron
 *      https://www.lintcode.com/problem/158?n
 *      Write a method anagram(s,t) to decide if two strings are anagrams or not.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(const string &s,const string &t) {
        auto size=s.length();
        if(size!=t.length())
            return false;
        vector<int> S(0xff);
        for(auto c:s)
            ++S[c];
        for(auto c:t)
            --S[c];        
        for(auto p:S)
            if(p)
                return false;
        return true;
            
    }
};
//*
int main(){
    Solution s;
    if( s.anagram("ab","ab")&&
        s.anagram("abcd","dcba") &&
        !s.anagram("ac","ab"))
        cout<<"SUCCEED!";
    else
        cout<<"FAILED!";
	return 0;
}


