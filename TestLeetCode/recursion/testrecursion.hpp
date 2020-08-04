#pragma once
#include <iostream>
#include <vector>

using namespace std;

//All tests on Arrays without using C++ std functions

namespace test_recursion
{
    inline void reverser(vector<char>& s, int b, int e)
    {
        if (b < e)
        {
            swap(s[b++], s[e--]);
            reverser(s, b, e);
        }
    }

    inline void reverseString(vector<char>& s)
    {
        const int end = static_cast<int>(s.size() - 1);
        reverser(s, 0, end);
    }

    void test_reverseString()
    {
        // Input: ["h", "e", "l", "l", "o"]
        std::vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
        cout << "From:" << endl;
        for (char& i : s)
            cout << i << ends;
        cout << endl;

        cout << "To:" << endl;
        reverseString(s);

        for (char& i : s)
            cout << i << ends;
        cout << endl;
    }

    //------------------------------------------------

    /**
 * Definition for singly-linked list.*/
    namespace swapNodes
    {
        struct ListNode
        {
            int val;
            ListNode* next;

            ListNode() : val(0), next(nullptr)
            {
            }

            ListNode(int x) : val(x), next(nullptr)
            {
            }

            ListNode(int x, ListNode* next) : val(x), next(next)
            {
            }
        };

        class Solution
        {
        public:
            ListNode* swapPairs(ListNode* head)
            {
                if (head && head->next)
                {
                    swap(head->val, head->next->val);
                    if (head->next->next)
                    {
                        swapPairs(head->next->next);
                    }
                }

                return head;
            }
        };

        void test_swapNodes()
        {
            Solution sol;

            //ListNode arr() = { 1,2,3,4,5 };

            ListNode a4(4);
            ListNode a3(3, &a4);
            ListNode a2(2, &a3);
            ListNode a1(1, &a2);
            sol.swapPairs(&a1);
            ListNode* n = &a1;
            while (n)
            {
                cout << n->val << ends;
                n = n->next;
            }
            cout << endl;
        }
    }
};
