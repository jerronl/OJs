/*
 * 171. Anagram.cpp
 *
 *      Author: jerron
 *      https://www.lintcode.com/problem/171
 *      Given an array of strings, return all groups of strings that are anagrams.
 */
#include "../utils/utils.h"

class Solution {
public:
	/**
	 * @param s: The first string
	 * @param t: The second string
	 * @return: true or false
	 */
	vector<string> anagrams(vector<string> &strs)  {
		unordered_map<string,vector<size_t> > M;
        for(size_t i=0,n=strs.size();i<n;++i){
            string s=strs[i];
            sort(s.begin(),s.end());
            auto v=M.find(s);
            if(v==M.end())
                M.emplace(s,vector<size_t>{i});
            else
                v->second.push_back(i);
        }
		vector<string> result;
        for(auto &m:M)
            if(m.second.size()>1)
                for(auto i:m.second)
                    result.push_back(strs[i]);
		return result;
	}
};

int main() {
	Solution s;
    vector<pair<vector<string>,vector<string>>> tests={
        {{"lint", "intl", "inlt", "code"},{"lint", "inlt", "intl"}},
        {{"ab", "ba", "cd", "dc", "e","ab"},{"ab", "ba", "ab", "cd", "dc"}},
        {{},{}},
        {{"ab",  "cd"},{}}
    };

    for (auto test : tests) {
        auto tmp=s.anagrams(test.first);
        if (!asserteqv(tmp,test.second)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
}

