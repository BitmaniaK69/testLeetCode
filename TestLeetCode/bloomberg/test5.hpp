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
     /*
        bool maxExist=false;
     bool minExist=false;

   bool isValidBSTR(TreeNode* root, int min, int max, TreeNode* parent ) {
             if (!root)
                 return true;

             if (!maxExist)
             {
                 max = root->val;
                 maxExist=true;
             }
             if (!minExist)
             {
                 min = root->val;
                 minExist=true;
             }

             bool isLeft = root->val < max || !parent ;
             bool isRight =  root->val > min || !parent;

             if (!isLeft || !isRight)
                 return false;

             return isValidBSTR(root->left, min, root->val, root) && isValidBSTR(root->right, root->val, max, root);
         }



         bool isValidBST(TreeNode* root) {
             if (root == nullptr)
                 return true;

         maxExist=false;
         minExist=false;
         return isValidBSTR(root,  0, 0, nullptr);
     }

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
        bool isValidBST2(TreeNode* root, TreeNode* min = nullptr, TreeNode* max = nullptr) {
            if (!root) return true;
            if (min && root->val <= min->val) return false;
            if (max && root->val >= max->val) return false;
            return isValidBST2(root->left, min, root) && isValidBST2(root->right, root, max);
        }

        bool isValidBST(TreeNode* root) {
            if (root == nullptr)
                return true;

            return isValidBST2(root);
        }
        void test_isValidBST()
        {
            TreeNode a1(1);
            TreeNode a3(3);
            TreeNode a2(2, &a1, &a3);

            TreeNode b1(1);
            TreeNode b3(3);
            TreeNode b6(6);
            TreeNode b4(4, &b3, &b6);
            TreeNode b5(6, &b1, &b4);

            TreeNode c5(5);
            TreeNode c6(6);
            TreeNode c20(20);
            TreeNode c15(15, &c6, &c20);
            TreeNode c10(10, &c5, &c15);



            TreeNode d0(0);
            TreeNode d2(2);
            TreeNode d4(4);
            TreeNode d6(6);

            TreeNode d1(1, &d0, &d2);
            TreeNode d5(5, &d4, &d6);
            TreeNode d3(3, &d1, &d5);

            TreeNode e1(INT_MAX);
            TreeNode e2(INT_MAX, &e1, nullptr);

            bool res2 = isValidBST(&e2); // expected false
            bool res1 = isValidBST(&d3); // expected true
            bool res = isValidBST(&a2); // expected true
            res = isValidBST(&b5); // expected false
            res = isValidBST(&c10); // expected false
        }

    }


};
