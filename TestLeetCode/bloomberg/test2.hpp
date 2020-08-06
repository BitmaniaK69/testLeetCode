#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
namespace bloomberg
{
    /*
     Given an array nums of n integers, are there elements a, b, c in nums
     such that a + b + c = 0?
     Find all unique triplets in the array which gives the sum of zero.
     */

    namespace test2 {

        //My solution works but is not super optimized 
        /*vector<vector<int>> threeSum(vector<int>& nums) {

            set<vector<int>> bag;
            for (int a = 0; a < nums.size(); ++a)
            {
                for (int b = a + 1; b < nums.size(); ++b)
                {
                    const auto ida = nums[a];
                    const auto idb = nums[b];
                    const auto idc = -(ida + idb);
                    if (std::find(nums.begin() + b + 1, nums.end(), idc) != nums.end())
                    {

                        std::vector<int> v = { ida,idb,idc };
                        std::sort(v.begin(), v.end());
                        bag.insert(v);
                    }

                }
            }

            return vector<vector<int>>(begin(bag), end(bag));;
        }*/

        vector<vector<int>> threeSum(vector<int>& nums) {
            set<vector<int>> res;
            unordered_set<int> dups;
            unordered_map<int, int> seen;
            for (int i = 0; i < nums.size(); ++i)
                if (dups.insert(nums[i]).second) {
                    for (int j = i + 1; j < nums.size(); ++j) {
                        int complement = -nums[i] - nums[j];
                        auto it = seen.find(complement);
                        if (it != end(seen) && it->second == i) {
                            vector<int> triplet = { nums[i], nums[j], complement };
                            sort(begin(triplet), end(triplet));
                            res.insert(triplet);
                        }
                        seen[nums[j]] = i;
                    }
                }
            return vector<vector<int>>(begin(res), end(res));
        }
        void test_threeSum()
        {
            vector<int> nums = { -1, 0, 1, 2, -1, -4 }; // expected {{-1, 0, 1},{-1, -1, 2}}
            auto v = threeSum(nums);

        }
    }


};
