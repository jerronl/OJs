/*
 * 38.searchMatrix.cpp
 *
 *  Created on: Feb 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/183
 *     Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty())
            return 0;
        int x = 0, y = matrix.size() - 1, n = matrix.front().size(), s = 0;
        for (; x < n && y > -1;) {
            if (matrix[y][x] == target)
                ++s, ++x, --y;
            else if (matrix[y][x] > target)
                --y;
            else
                ++x;
        }
        return s;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<vector<int>>,int>,int>> tests={
            {{{{3,4}}, 3}, 1},
            {{{{3,4}}, 1}, 0},
            {{{     {1, 3, 5, 7},
                    {2, 4, 7, 8},
                    {3, 5, 9, 10}}, 3}, 2},
            {{{     {1, 3, 5, 7},
                    {2, 4, 7, 8},
                    {3, 5, 9, 10}}, 6}, 0},
            {{{     {1, 3, 5, 7},
                    {2, 4, 7, 8},
                    {3, 5, 9, 10}}, 0}, 0},
            {{{     {1, 3, 5, 7},
                    {2, 4, 7, 8},
                    {3, 5, 9, 10}}, 100}, 0},
            {{{{}}, 5}, 0}
    };
    for (auto test : tests) {
        auto tmp=s.searchMatrix(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }














