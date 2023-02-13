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
public:
    int count=0;
    void solver(TreeNode* root,int max){
        if(!root){
            return;
        }
        if(root->val>=max){
            count++;
            max=root->val;
        }
        if(root->left){
            solver(root->left,max);
        }
        if(root->right){
            solver(root->right,max);
        }
        return;
    }
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        solver(root,root->val);
        return count;
    }
};