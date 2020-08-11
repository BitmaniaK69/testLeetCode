#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


namespace test_tree_symmetrical {
/*
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

        1
       / \
      2   2
     / \ / \
    3  4 4  3


    But the following [1,2,2,null,3,null,3] is not:

        1
       / \
      2   2
       \   \
       3    3
*/
    class Solution {
    public:

        void breadthFirst(TreeNode* root, vector<int>& resl)
        {
            queue<TreeNode*> q;
            if (!root) {
                return;
            }
            q.push(root);
            while (!q.empty())
            {
                TreeNode* temp_node = q.front();
                q.pop();
                if (temp_node)
                {
                    resl.emplace_back(temp_node->val);
                    q.push(temp_node->left);
                    q.push(temp_node->right);
                }
                else
                    resl.emplace_back(-1);
            }
        }


        void breadthFirstR(TreeNode* root, vector<int>& resl)
        {
            queue<TreeNode*> q;
            if (!root) {
                return;
            }
            q.push(root);

            while (!q.empty())
            {
                TreeNode* temp_node = q.front();
                q.pop();
                if (temp_node)
                {
                    resl.emplace_back(temp_node->val);
                    q.push(temp_node->right);
                    q.push(temp_node->left);
                }
                else
                    resl.emplace_back(-1);
            }
        }

        bool isSymmetric(TreeNode* root) {

            vector<int> resl = {};
            vector<int> resr = {};
            breadthFirst(root, resl);
            // std::for_each(resl.begin(), resl.end(), [](const int & val) { std::cout<<val<<std::endl; });

            breadthFirstR(root, resr);
            // std::for_each(resr.begin(), resr.end(), [](const int & val) { std::cout<<val<<std::endl; });
            return resl == resr;

        }

        //------------------------------------------------------
        //This is a very good recursive solution
        //------------------------------------------------------
        /*
            class Solution {
        public:
            bool isSymmetric(TreeNode* root) {
                if(!root){
                    return true;
                }
                return isStmmetric0(root->left,root->right);
            }
            bool isStmmetric0(TreeNode* left,TreeNode* right){
                if(!left||!right){
                    return !left && !right;
                }
                return (left->val == right->val) && isStmmetric0(left->right,right->left) && isStmmetric0(left->left,right->right);
            }
        };*/
    }
};


