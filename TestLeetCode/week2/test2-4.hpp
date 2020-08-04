#pragma once

using namespace std;

/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

namespace test2_4
{
    // Definition for a binary tree node.

    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr)
        {
        }

        TreeNode(int x) : val(x), left(nullptr), right(nullptr)
        {
        }

        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
        {
        }
    };

    class Solution
    {
    public:

        int diameterCount(TreeNode* root, int& ans) const
        {
            if (!root)
                return 0;
            const int total1 = diameterCount(root->left, ans);
            const int total2 = diameterCount(root->right, ans);
            ans = max(ans, total1 + total2 + 1);
            return max(total1, total2) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root) const
        {
            auto maxval = 1;
            diameterCount(root, maxval);
            return maxval - 1;
        }
    };

    inline void test()
    {
        TreeNode t5(5);
        TreeNode t4(4);
        TreeNode t2(2, &t4, &t5);
        TreeNode t3(3);
        TreeNode t1(1, &t2, &t3);
        Solution sol;
        cout << "diameterOfBinaryTree: " << sol.diameterOfBinaryTree(&t1) << endl;
        cout << "diameterOfBinaryTree: " << sol.diameterOfBinaryTree(&t5) << endl;
    }
};
