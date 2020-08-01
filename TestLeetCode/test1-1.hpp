#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

/*
 SINGLE NUMBER
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/


using namespace std;

class Solution {
public:
    static int singleNumber(std::vector < int >& nums) {
        int res = -1;
        std::sort(nums.begin(), nums.end());

        for (auto n : nums) {
            if (res == -1) {
                res = n;
            }
            else if (n != res && res != -1) {
                return res;
            }
            else {
                res = -1;
            }
        }
        return res;
    }
};

void test1_1()
{
    std::vector < int >vals = { 3,3,4,1,2,1,2,5,4 };
    cout << Solution::singleNumber(vals) << endl;

}

