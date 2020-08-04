#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/
namespace test1_5
{
    class Solution
    {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) const
        {
            vector<vector<string>> res;
            unordered_map<string, std::vector<string>> anagrams;

            for (const auto& word : strs)
            {
                string wordkey = word;
                std::sort(wordkey.begin(), wordkey.end());
                anagrams[wordkey].push_back(word);
            }
            res.reserve(anagrams.size());

            for (const auto& x : anagrams)
            {
                res.push_back(x.second);
            }
            return res;
        }
    };

    inline void test()
    {
        const Solution sol;

        std::vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
        for (auto w : sol.groupAnagrams(v))
        {
            for (auto z : w)
            {
                cout << z << endl;
            }
            cout << endl;
        }
    }
};
