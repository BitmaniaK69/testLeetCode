#pragma once
#include <string>

using namespace std;
namespace bloomberg
{
    /*
    Given two strings s and t , write a function to determine if t is an anagram of s.
     */

    namespace test3 {
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false;
            std::unordered_map<char, int> letters;
            for (const auto& l : s)
            {
                letters[l]++;
            }
            for (const auto& l : t)
            {
                letters[l]--;
            }

            for (const auto& t : letters)
            {
                if (t.second != 0) return false;
            }
            return true;
        }

        void test_isAnagram()
        {
            auto v = isAnagram("anagram", "nagaram"); //expected true
            v = isAnagram("rat", "car"); //expected false
        }
    }


};
