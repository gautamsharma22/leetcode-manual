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
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        bool null_node_found = false;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if (temp == nullptr)
            {
                null_node_found = true;
            }
            else
            {
                if (null_node_found)
                    return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};

/*
Notes:-

If we see any null value it should be the last value;
(It works on last level also because node are expected to be in extreme left.)

*/