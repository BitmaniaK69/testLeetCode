/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <vector>
#include <iostream>
#include <queue>

namespace testbench
{
    class Sample
    {
    public:
        // Copy Constructor should not be private if we are inserting it's
        // objects in std::vector
        Sample(const Sample& obj)
        {
            std::cout << "Sample :: Copy Constructor" << std::endl;
        }
        Sample()
        {
            std::cout << "Sample :: Default Constructor" << std::endl;
        }
        Sample& operator=(const Sample& obj)
        {
            std::cout << "Sample :: Assignment Operator" << std::endl;
        }
    };



    void test1()
    {
        std::vector<Sample> vecOfSamples;
        vecOfSamples.reserve(10);
        Sample obj;

        std::cout << "emplace_back" << std::endl;
        vecOfSamples.emplace_back(obj);

        std::cout << "push_back" << std::endl;
        vecOfSamples.push_back(obj);

        std::cout << "emplace_back" << std::endl;
        vecOfSamples.emplace_back(obj);
    }

    void test2()
    {
        std::vector<int> vecArr;
        for (int i = 1; i <= 10; i++)
            vecArr.push_back(i);

        for (auto it = vecArr.begin(); it != vecArr.end(); it++)
            std::cout << (*it) << "  ";

        std::cout << std::endl;

        // Erase and element with value 5.
        auto it = std::find(vecArr.begin(), vecArr.end(), 5);
        if (it != vecArr.end())
            vecArr.erase(it);


        // Now iterator 'it' is invalidated because it still points to
        // old location, which has been deleted. So, if you will try to
        // do the use the same iterator then it can show undefined
        // behavior.

        for (; it != vecArr.end(); it++)
        {
            //std::cout << (*it) << "  ";         // Unpredicted Behavior
            it = vecArr.erase(it);                //update the value of iterator ‘it’  
            std::cout << (*it) << "  ";

        }
    }

    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
    class Solution {
        // Definition for a binary tree node.
        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        };

    public:
        int maxDepth(TreeNode* root) {
            if (!root) {
                return 0;
            }
            queue<TreeNode*> q;
            q.push(root);
            int level = 0;

            while (!q.empty()) {

                const int size = static_cast<int>(q.size());

                for (int i = 0; i < size; ++i) {
                    TreeNode* elem = q.front();
                    q.pop();
                    if (elem->left) {
                        q.push(elem->left);
                    }
                    if (elem->right) {
                        q.push(elem->right);
                    }
                }

                ++level;
            }
            return level;


        }
    };

}
