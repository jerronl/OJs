/*
 * cakes.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: jerron
 *      http://dsalgo.openjudge.cn/stackqueue/8/
 *     minize move from n to k. Each move is one of (+1, -1, 2*x)
 */
#include <iostream>     //istream
#include <sstream>      //istringstream 
#include <vector>
int catchcow(std::istream& in) {
    int n, k, move=INT_MAX,step=0,left=0,right,i;
    in >> n >> k;
    std::vector<int> steps(k+1,INT_MAX),q;
    auto addQ=[k,&q,&move,&step,&steps](int n)->bool{
        if(n>=k){
            auto move_new=n-k+step;
            if(move>move_new)
                return (move=move_new)>step;
        }else if (n>=0&&steps[n]>step){
            steps[n]=step;
            q.push_back(n);
        }        
        return true;
    };
    addQ(n);
    for(step=1;step<move;++step,left=right){
        for(i=left,right=q.size();i<right;++i){
            n=q[i];
            if(!(addQ(n-1)&&addQ(n+1)&&addQ(n*2)))
                break;
        }
    }
    return move;
}
int main() {
    std::vector<std::pair<std::string, int>> testcases{
        {"0 0",0},
        {"1 1",0},
        {"100 100",0},
        {"0 1",1},
        {"1 0",1},
        {"8 17",2},
        {"8 15",2},
        {"4 17",3},
        {"100000 0",100000},
        {"5 17",4}
   };
    for (auto& testcase : testcases) {
        std::istringstream is(testcase.first);
        auto result = catchcow(is);
        if (result != testcase.second) {
            std::cout << "failed case:\n" << testcase.first << "\n result " << result << "\n expect " << testcase.second;
            return -1;
        }
    }

    std::cout << "SUCCEED!";
    return 0;
}









