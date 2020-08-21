#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
namespace test_criterion1
{
    /*
    A lucky number is a 10-based number, which has at least a "6" or an "8" in its digits.
    However, if it has "6" and "8" at the same time, then the number is NOT lucky.
    For example, "16", "38", "666" are lucky numbers, while "234" , "687" are not.
     */
    inline bool isLucky(unsigned int n)
    {
        auto has8 = false;
        auto has6 = false;

        while (n > 0)
        {
            const auto d = n % 10;
            if (d == 8)
            {
                has8 = true;
            }
            else if (d == 6)
            {
                has6 = true;
            }
            n /= 10;
            if (has6 && has8)
            {
                return false;
            }
        }
        return has6 || has8;
    }

    inline int isLuckyNumber(unsigned int l, unsigned h)
    {
        int luckies = 0;
        for (auto n = l; n <= h; ++n)
        {
            if (isLucky(n))
            {
                ++luckies;
//                cout << "found: " << n << endl;
            }
        }
        return luckies;
    }
    void test_luckyNumber()
    {
        cout << isLuckyNumber(230, 682) << endl;
    }

}
