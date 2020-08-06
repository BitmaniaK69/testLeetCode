#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

//All tests on Arrays without using C++ std functions

namespace test_memoization
{
    namespace test_fibonacci
    {
        class Solution {
        public:
            unordered_map<int, int> cache;
            int fib(int N) {
                if (N < 2) return N;
                if (cache.find(N) != cache.end())
                {
                    return cache[N];
                }

                const auto res = fib(N - 1) + fib(N - 2);
                cache[N] = res;
                return res;
            }
        };
        inline void test_fibonacci()
        {
            Solution sol;
            cout << sol.fib(2) << endl;
            cout << sol.fib(3) << endl;
            cout << sol.fib(4) << endl;

        }
    }

    //-------------------------------------------------------------------------
    //Climbing Stairs

    namespace test_climbingstairs
    {
        class Solution {
        public:
            unordered_map<int, int> cache;
            int climbStairs(int n) {
                return climb_Stairs(0, n);
            }

            int climb_Stairs(int i, int n) {
                if (i > n) {
                    return 0;
                }
                if (i == n) {
                    return 1;
                }
                if (cache.find(i) != cache.end())
                {
                    return cache[i];
                }
                const int val = climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
                cache[i] = val;
                return val;
            }
        };

        inline void test_climbStairs()
        {
            Solution sol;
            cout << sol.climbStairs(2) << endl;
            cout << sol.climbStairs(3) << endl;
            cout << sol.climbStairs(4) << endl;
        }
    }
};
