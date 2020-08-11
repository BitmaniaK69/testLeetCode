#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
/*
    Shuffle a set of numbers without duplicates.

    Example:

    // Init an array with set 1, 2, and 3.
    int[] nums = { 1,2,3 };
    Solution solution = new Solution(nums);

    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
    solution.shuffle();

    // Resets the array back to its original configuration [1,2,3].
    solution.reset();

    // Returns the random shuffling of array [1,2,3].
    solution.shuffle();
*/
namespace test_design
{

    class Solution {
    public:
        Solution(vector<int>& nums) : orig(nums) {
        }

        /** Resets the array to its original configuration and return it. */
        vector<int> reset() {
            res = orig;
            /*std::vector<int> res = {};
            std::copy(orig.begin(), orig.end(),  std::back_inserter(res));*/
            return res;
        }

        /** Returns a random shuffling of the array. */
        vector<int> shuffle() {
            // res=orig;
            res = orig;
            //std::copy(orig.begin(), orig.end(),  std::back_inserter(res));
            /*random_shuffle(res.begin(), res.end());
            return res;
            */
            //Shuffling is faster in this way
            const int size = static_cast<int>(res.size());
            for (int i = 0; i < size; ++i)
            {
                std::swap(res[i], res[rand() % size]);
            }
            return res;
        }

        std::vector<int> orig;
        std::vector<int> res;
    };


    void test_shuffle()
    {

        /**
         * Your Solution object will be instantiated and called as such:
         * Solution* obj = new Solution(nums);
         * vector<int> param_1 = obj->reset();
         * vector<int> param_2 = obj->shuffle();
         */
    }

}
