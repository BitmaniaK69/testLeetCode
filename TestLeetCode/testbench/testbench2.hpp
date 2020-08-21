#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

//Some experiments

using namespace std;
namespace testbench2 {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };


    void BFS(TreeNode* root, std::vector<int>& res)
    {
        if (!root)
        {
            return;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node)
            {
                res.emplace_back(node->val);
                //for all the linked nodes push to the queue
                q.push(node->left);
                q.push(node->right);
            }
        }
    }

    int add_numbers(int a, int b) {
        return a + b;
    }

    TreeNode* build()
    {
        TreeNode* root = new TreeNode(1);
        TreeNode* root2 = new TreeNode(2);
        TreeNode* root3 = new TreeNode(3, root, root2);

        TreeNode* root4 = new TreeNode(4);
        TreeNode* root5 = new TreeNode(5);
        TreeNode* root6 = new TreeNode(6, root4, root5);

        TreeNode* root7 = new TreeNode(7, root3, root6);
        return root7;
    }

    int test_main() {
        int num1, num2;
        int sum;
        cin >> num1 >> num2;

        sum = add_numbers(num1, num2);
        cout << "The sum is " << sum << endl;

        TreeNode* root = build();
        std::vector<int> res;
        BFS(root, res);

        std::for_each(res.begin(), res.end(), [](const int v) { cout << v << endl; });

        return 0;
    }
}
