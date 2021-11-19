/*
 * cakes.cpp
 *
 *  Created on: Nov 18, 2021
 *      Author: jerron
 *      
 *     Each of k guys might get no more than one of the n cakes after everyone will send a wishlist of the acceptable numbers of the cake. Trying maximize the number of guys who get the cake in his list.
 *     input is the number n and k in the first line followed by the k lines of each guys wishlist.
 */
#include <iostream>     //istream
#include <sstream>      //istringstream 
#include <string>       //getline
#include <vector>
#include <map>
#include <set>
#include <iterator>     //istream_iterator

int cake_assign(std::istream& in) {
    int n, k, assigned=0;
    in >> n >> k;
    std::vector<std::set<int>> cakes(n+1), wishlists;
    std::map<int, std::set<int>,std::greater<int>> cake_cnt;
    std::vector< std::set<int> > all_integers;
    for (auto i = 0; i <= k; ++i) {
        std::string line;
        std::getline(in, line);
        std::istringstream is(line);
        wishlists.push_back(
            std::set<int>(std::istream_iterator<int>(is),
                std::istream_iterator<int>()));
        for (auto cake : wishlists.back())
            cakes[cake].insert(i);
    }
    for (auto i = 1; i <= n; ++i)
        if (cakes[i].size() > 0) cake_cnt[cakes[i].size()].insert(i);
    while (!cake_cnt.empty())
        if (cake_cnt.rbegin()->second.empty())
            cake_cnt.erase(cake_cnt.rbegin()->first);
        else{
        auto cake =* cake_cnt.rbegin()->second.begin();
        size_t greed = n + 1, winner=-1;
        auto &eaters = cakes[cake];
        for(auto eater : eaters)
            if (wishlists[eater].size() < greed) {
                greed = wishlists[eater].size();
                winner = eater;
            }
        ++assigned;

        for (auto wish : wishlists[winner]) {
            auto neaters = cakes[wish].size();
            cake_cnt[neaters].erase(wish);
            cakes[wish].erase(winner);
            if (neaters > 1 && wish!=cake)
                cake_cnt[neaters - 1].insert(wish);
        }
        for (auto eater : eaters)
            wishlists[eater].erase(cake); 
        }
    return assigned;
}
int main() {
    std::vector<std::pair<std::string, int>> testcases{
        {R"(4 4
        1
        1 2
        2 3
        3 )",3},
        {R"(4 4
        1 2
        1 3
        1 4
        2 3)",4},
         {R"(4 4
        1
        1 
        2 3
        3 4)",3},
   };
    for (auto& testcase : testcases) {
        std::istringstream is(testcase.first);
        auto result = cake_assign(is);
        if (result != testcase.second) {
            std::cout << "failed case:\n" << testcase.first << "\n result " << result << "\n expect " << testcase.second;
            return -1;
        }
    }

    std::cout << "SUCCEED!";
    return 0;
}









