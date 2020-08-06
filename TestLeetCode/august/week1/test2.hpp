#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
namespace august_week1
{
    namespace test2 {
        //Given a word, you need to judge whether the usage of capitals in it is right or not.

        class Solution {
        public:



            //Solution 1 simple, not optimized
            bool detectCapitalUse1(string word) {

                std::string str = word;
                std::transform(word.begin(), word.end(), str.begin(), ::toupper);
                if (str == word)
                {
                    return true;
                }
                std::transform(word.begin(), word.end(), str.begin(), ::tolower);
                if (str == word)
                {
                    return true;
                }
                std::transform(word.begin(), word.begin() + 1, str.begin(), ::toupper);
                if (str == word)
                {
                    return true;
                }
                return false;
            }

            enum class statusCase
            {
                none = 0, up, low
            };
            bool detectCapitalUse(string word) {
                statusCase lastCase = statusCase::none;
                bool first = true;
                for (auto c : word)
                {
                    if (c >= 65 && c <= 90)//Uppercase
                    {
                        if (lastCase == statusCase::low)
                        {
                            return false;
                        }
                        if (first)
                        {
                            first = false;
                        }
                        else
                        {
                            lastCase = statusCase::up;
                        }
                    }
                    else if (c >= 97 && c <= 122)//lowcase
                    {
                        if (first)
                        {
                            first = false;
                        }
                        else if (lastCase == statusCase::up)
                        {
                            return false;
                        }
                        lastCase = statusCase::low;
                    }

                }

                return true;
            }
        };

        inline void test_capital()
        {
            Solution sol;
            cout << sol.detectCapitalUse("FFFFFFFFFFFFFFFFFFFFf") << endl;
            cout << sol.detectCapitalUse("Leetcode") << endl;
            cout << sol.detectCapitalUse("USA") << endl;
            cout << sol.detectCapitalUse("FlaG") << endl;


        }
    }
};
