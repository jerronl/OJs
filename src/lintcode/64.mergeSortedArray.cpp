/*
 * 64.mergeSortedArray.cpp
 *
 *  Created on: Feb 14, 2021
 *      https://www.lintcode.com/problem/64
 *      Given two sorted integer arrays A and B, merge B into A as one sorted array.
 */
#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        auto i=m+n,j=m-1,k=n-1;
        while(j>=0&&k>=0)
            if(A[j]>B[k])
                A[--i]=A[j--];
            else
                A[--i]=B[k--];
        while(j>=0)
            A[--i]=A[j--];;
        while(k>=0)
            A[--i]=B[k--];
    }
};

int main() {
	Solution s;
	vector<pair<pair<pair<vector<int>,int>,pair<vector<int>,int>>, vector<int>>> tests ={
			{{{{}, 0  },{{4,5},  2}},{4,5}},
			{{{{1, 2, 3}, 3  },{{4,5},  2}},{1,2,3,4,5}},
			{{{{1, 2, 5}, 3  },{{3,4},  2}},{1,2,3,4,5}}
	};
	for (auto test : tests) {
		vector<int> A( test.first.first.first),B(test.first.second.first);
		A.resize(test.first.first.second+test.first.second.second);
		s.mergeSortedArray(&A[0], test.first.first.second, &B[0], test.first.second.second);
		if (A != test.second) {
			cout << "FAILED!" << test << A;
			return 0;
		}
	}
	cout << "SUCCEED!";
	return 0;
}




