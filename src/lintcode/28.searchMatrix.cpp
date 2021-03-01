/*
 * 28.searchMatrix.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/28
 *     Write an efficient algorithm that searches for a value in an m x n matrix.
 *      */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix.front().empty())
            return false;
        int l = 0, m = matrix.size(), n = matrix.front().size(), r = m * n;
        while (l < r) {
            auto mid = (l + r) / 2;
            auto comp = matrix[mid / n][mid % n];
            if (comp == target)
                return true;
            if (comp > target)
                r = mid;
            else
                l = mid + 1;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<vector<int>>,int>,bool>> tests={
            {{{{1,4,5},
            {6,7,8}}, 9}, false},
            {{{{1,5,8,12,13,15,18,20,25,26,28,33,38,40,43,49,52,53,59},{84,100,110,129,141,156,177,198,220,242,254,266,284,297,316,326,343,358,373},{388,398,419,439,449,460,472,495,516,539,560,582,600,610,624,643,668,691,710},{720,733,751,765,787,804,814,832,856,880,905,930,950,974,999,1012,1022,1039,1061},{1081,1091,1102,1126,1151,1175,1194,1219,1239,1253,1263,1274,1287,1298,1308,1318,1337,1361,1382},{1404,1417,1437,1452,1466,1487,1503,1518,1537,1555,1578,1590,1601,1613,1636,1659,1669,1688,1712}}, 1888}, false},
            {{{{1,4,5},
            {6,7,8}}, 8}, true},
            {{{{}}, 2}, false},
            {{{{5}}, 2}, false},
            {{{{1,3,5,7},
            {10,11,16,20},
            {23,30,34,50}}, 3}, true}
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







