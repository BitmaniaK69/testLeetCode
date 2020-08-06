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


    //-------------------------------------------------------------------------
    namespace searchBST
    {
        //  Definition for a binary tree node.
            /*
             Given the tree:
                4
               / \
              2   7
             / \
            1   3

        And the value to search: 2
             */
        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        };

        class Solution {
        public:
            TreeNode* searchBST(TreeNode* root, int val) {
                if (root != nullptr)
                {

                    if (root->val == val)
                    {
                        return root;
                    }
                    if (auto* const resL = searchBST(root->left, val))
                        return resL;
                    
                    if (auto* const resR = searchBST(root->right, val))
                        return resR;
                }
                return nullptr;
            }


            void printBST(TreeNode* root) {
                if (root != nullptr)
                {
                    cout << root->val << ends;
                    printBST(root->left);
                    printBST(root->right);
                }
            }

           
        };

        inline void test_searchBST()
        {
            //Input: 1->2->3->4->5->NULL
            //Output: 5->4->3->2->1->NULL
            Solution sol;
            TreeNode a3(3);
            TreeNode a1(1);
            TreeNode a2(2, &a1, &a3);
            TreeNode a7(7);
            TreeNode a4(4, &a2, &a7);


            TreeNode* n = sol.searchBST(&a4, 2);
            sol.printBST(n);
            cout << endl;
        }
    }


};
