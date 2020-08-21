#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
namespace test_criterion2
{
    /*
    A palindrome is a sequence of letters which reads the same backward as forward, like “madam” for example.

    Near palindrome is a word on letter away from being a palindrome (replacemente, addition or removal

    M A D A M

    */




    inline bool isNearPalindrome(std::string word)
    {
        int differences = 0;
        int i = 0;
        int j = static_cast<int>(word.size())-1;
        while (i<=j)
        {
            if (word[i]==word[j])
            {
                ++i;
                --j;
            }
            else// AABAA
            {
                if (differences > 0)
                {
                    return false;
                }
                ++differences;

                if (j - 1 >= i && word[j-1]==word[i])
                {
                    --j;
                }
                else if (i + 1 <= j && word[i + 1] == word[j])
                {
                    ++i;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    #define DUMP_TEST(WORD)     cout << "Word:" << WORD << " IsNearPalindrome:" << (isNearPalindrome(WORD)?"Y":"N") << endl;
    void test_isNearPalindrome()
    {

        DUMP_TEST("MADAM");
        DUMP_TEST("MADSAM");
        DUMP_TEST("MADSSAM");
        DUMP_TEST("MASDSAM");
        DUMP_TEST("MADSAAM");
        DUMP_TEST("MOOSE");
        DUMP_TEST("ADAM");
    }

}


