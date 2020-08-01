#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;
/*
 HAPPY NUMBER

 Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/


class Solution2 {
public:
    bool isHappy(int n) {
        int sum = 0;
        static std::set<int> processed = {};
        while (n >= 1)
        {
            auto val = n % 10;
            auto val2 = val * val;
            n /= 10;
            sum += val2;
        }
        cout << sum << endl;
        if (sum == 1) return true;
        if (std::find(processed.begin(), processed.end(), sum) != processed.end())
        {
            return false;
        }
        processed.insert(sum);
        return isHappy(sum);
    }
};




void test1_2()
{

    Solution2 sol;
    cout << (sol.isHappy(13) ? "true" : "false") << endl;

}
