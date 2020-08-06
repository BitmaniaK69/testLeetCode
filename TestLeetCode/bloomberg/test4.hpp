#pragma once
#include <string>

using namespace std;
namespace bloomberg
{
    /*
    Given two strings s and t , write a function to determine if t is an anagram of s.
     */

    namespace test4 {

        struct ListNode {
            int val;
            ListNode* next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode* next) : val(x), next(next) {}
        };

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* base = nullptr;
            ListNode* digit = nullptr;
            int carry = 0;
            while (l1 || l2 || carry)
            {
                int tot = carry;
                if (l1) tot += l1->val;
                if (l2) tot += l2->val;
                carry = 0;

                if (tot >= 10)
                {
                    carry = 1;
                    tot %= 10;
                };
                auto* prec = digit;
                digit = new ListNode(tot);
                if (base == nullptr) {
                    prec = digit;
                    base = prec;
                }
                else
                {
                    prec->next = digit;
                }
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            }
            return base;
        }

        void test_addTwoNumbers()
        {
            ListNode a1(3);
            ListNode a2(4, &a1);
            ListNode a3(2, &a2);

            ListNode b1(4);
            ListNode b2(6, &b1);
            ListNode b3(5, &b2);
            // (2 -> 4 -> 3) + (5 -> 6 -> 4) expected (7 -> 0 -> 8)
            ListNode* res = addTwoNumbers(&a3, &b3);
        }
        void test_addTwoNumbers2()
        {
            ListNode a1(5);

            ListNode b1(5);
            // (2 -> 4 -> 3) + (5 -> 6 -> 4) expected (7 -> 0 -> 8)
            ListNode* res = addTwoNumbers(&a1, &b1);
        }
    }


};
