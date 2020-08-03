#pragma once

#include <iostream>

using namespace std;


/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

namespace test2_2
{

    class Solution {
    public:
        static bool backspaceCompare(const string& S, const string& T) {
            string S1;
            string T1;

            for (char c : S)
            {
                if (c == '#')
                {
                    if (!S1.empty())
                    {
                        S1.pop_back();
                    }
                }
                else
                    S1 += c;
            }
            for (char c : T)
            {
                if (c == '#')
                {
                    if (!T1.empty())
                    {
                        T1.pop_back();
                    }
                }
                else
                    T1 += c;
            }
            return S1 == T1;
        }
    };

    inline void test()
    {
        string S;
        string T;
        Solution sol;
        {
            S = "a##c";
            T = "#a#c";
            cout << (sol.backspaceCompare(S, T) ? "true" : "false") << endl;
        }
    }
};
