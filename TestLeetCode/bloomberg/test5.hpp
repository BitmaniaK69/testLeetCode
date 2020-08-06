#pragma once
#include <string>

using namespace std;
namespace bloomberg
{
    /*
    Given a binary tree, determine if it is a valid binary search tree (BST).

        Example 1:
            2
           / \
          1   3
        Input: [2,1,3]
        Output: true

        Example 2:
            5
           / \
          1   4
             / \
            3   6
        Input: [5,1,4,null,null,3,6]
        Output: false
     */

    namespace test5 {

        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        };

        bool isValidBST(TreeNode* root) {
            return false;
        }

        void test_isValidBST()
        {
            TreeNode a1(1);
            TreeNode a3(3);
            TreeNode a2(2, &a1, &a3);

            TreeNode b1(1);
            TreeNode b3(3);
            TreeNode b6(6);
            TreeNode b4(4, &b3,&b6);
            TreeNode b5(6, &b1, &b4);


            bool res = isValidBST(&a2); // expected true
            res = isValidBST(&b5); // expected false
        }
        
    }


};
