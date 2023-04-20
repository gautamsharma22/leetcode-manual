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
    /*
        Approach 1: (TLE)

        (In this approach we are pushing null node also with their left and right childs.So the overall TC will be poor.)

        * Do Level Order Traversal and push Elements to queue.
        * At every level take only select non-null-leftmost node and non-null-rightmost node.(For that trim the queue at every level if there are trailing aur leading null's).
        * Update size using variable and return it.
    */
    int widthOfBinaryTree(TreeNode *root)
    {
        deque<TreeNode *> q;
        int maxi = 0;
        q.push_back(root);
        while (!q.empty())
        {
            while (!q.empty() && q.front() == NULL)
                q.pop_front();
            while (!q.empty() && q.back() == NULL)
                q.pop_back();
            int size = q.size();
            if (maxi < size)
                maxi = size;
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = q.front();
                q.pop_front();
                if (top == NULL)
                {
                    q.push_back(NULL);
                    q.push_back(NULL);
                }
                else
                {
                    q.push_back(top->left);
                    q.push_back(top->right);
                }
            }
        }
        return maxi;
    }
    /*
        Approach 2: Optimized Upto a level

        In this approach we'll be using Indexing Logic Used in Array to binary Tree's of Segment Trees that is :-
            (For 0 Based Indexing)
            Left=2*index+1;
            Right=2*index+2;
        * Push node at every level with correct index (Using Indexing logic).
        * Find out left most node (It will be at front of queue).
        * Find out right most node (It will be at back(end) of queue).
        * Calculate Distance (Right-Left+1).
        * Update and Store max and return it.
    */

    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        int maxi = 0;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            if (maxi < size)
                maxi = size;
            int leftMost = q.front().second;
            int rightMost = q.back().second;
            maxi = max(maxi, rightMost - leftMost + 1);
            for (int i = 0; i < size; i++)
            {
                auto top = q.front();
                int index = top.second;
                q.pop();
                if (top.first->left)
                    q.push({top.first->left, (long long)2 * index + 1});
                if (top.first->right)
                    q.push({top.first->right, (long long)2 * index + 2});
            }
        }
        return maxi;
    }
};