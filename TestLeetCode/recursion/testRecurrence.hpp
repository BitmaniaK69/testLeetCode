#pragma once
#include <iostream>
#include <vector>

using namespace std;

//All tests on Arrays without using C++ std functions


namespace test_recurrence
{
    //-------------------------------------------------------------------------
    namespace reverseList
    {
        struct ListNode {
            int val;
            ListNode* next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode* next) : val(x), next(next) {}
        };

        class Solution {
        public:

            void reverse(ListNode* node, ListNode*& res, ListNode* prec, ListNode*& last) {

                if (node->next != nullptr)
                {
                    reverse(node->next, res, node, last);
                }

                res = node;
                res->next = prec;
                if (last == nullptr)
                {
                    last = res;
                }
            }
            ListNode* reverseList(ListNode* head) {
                ListNode* res = nullptr;
                ListNode* last = nullptr;

                if (head != nullptr)
                {
                    reverse(head, res, nullptr, last);
                }
                return last;
            }

            ListNode* reverseList2(ListNode* head) {
                if (!head || !head->next) return head;
                ListNode* p = reverseList2(head->next);
                head->next->next = head;
                head->next = nullptr;
                return p;
            }
        };

        inline void test_reverseList()
        {
            //Input: 1->2->3->4->5->NULL
            //Output: 5->4->3->2->1->NULL
            Solution sol;
            ListNode a5(5);
            ListNode a4(4, &a5);
            ListNode a3(3, &a4);
            ListNode a2(2, &a3);
            ListNode a1(1, &a2);

            ListNode* n = sol.reverseList(&a1);
            while (n)
            {
                cout << n->val << ends;
                n = n->next;
            }
            cout << endl;
        }
    }
};
