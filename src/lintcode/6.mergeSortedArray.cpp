/*
 * 6.mergeSortedArray.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/64
 *      Merge two given sorted ascending integer array A and B into a new sorted integer array.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> *pA=&A,*pB=&B,res(A.size()+B.size());
        if(A.size()<B.size())
            swap(pA,pB);
        int iA=pA->size()-1,iB=pB->size()-1,ir=res.size();
        while(iB>=0)
            res[--ir]=(*pA)[iA]>(*pB)[iB]?(*pA)[iA--]:(*pB)[iB--];
        copy(pA->begin(),pA->begin()+ir,res.begin());
        return res;
    }
};
int main() {
    Solution s;
    vector<pair<pair<vector<int>, vector<int>>,vector<int>>> tests = {
            {{ {1 }, {1 } },{1,1}},
            {{ {1,2 }, {0 } },{0,1,2}},
            { { {1,2,3,4},{2,4,5,6} }, { 1,2,2,3,4,4,5,6 } }
    };
    for (auto test : tests) {
        auto tmp = s.mergeSortedArray(test.first.first,test.first.second);
        if (tmp != test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
}







