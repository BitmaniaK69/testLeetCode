#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
namespace bloomberg
{
    //Longest Substring Without Repeating Characters
    //Given a string, find the length of the longest substring without repeating characters.

    namespace test1 {
        int lengthOfLongestSubstring(string s) {
            std::string res;
            int max = 0;
            for (auto& c : s)
            {
                auto it = std::find(res.begin(), res.end(), c);
                if (it == res.end())
                {
                    res += c;
                }
                else
                {
                    const int len = static_cast<int>(res.size());
                    if (max < len)
                    {
                        max = len;
                    }
                    // we need to start from the next after the iterator
                    res = res.substr(res.find(c )+ 1);
                    res += c;
                }
            }

            const int len = static_cast<int>(res.size());
            if (max < len)
            {
                max = len;
            }
            return max;
        }
        void test_LongestSubstring()
        {
            cout << lengthOfLongestSubstring("aab") << endl;   //expected 2
            cout << lengthOfLongestSubstring("aabaab!bb") << endl;   //expected 3
            cout << lengthOfLongestSubstring("dvdf") << endl;   //expected 3
            cout << lengthOfLongestSubstring("au") << endl;   //expected 2
            cout << lengthOfLongestSubstring(" ") << endl;   //expected 1
            cout << lengthOfLongestSubstring("abcabcbb") << endl;   //expected 3
            cout << lengthOfLongestSubstring("bbbbb") << endl;   //expected 1
            cout << lengthOfLongestSubstring("pwwkew") << endl;   //expected 3
        }
    }


};
