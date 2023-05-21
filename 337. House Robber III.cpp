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
    unordered_map<TreeNode*,int> vis;
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(vis.count(root)>0){
            return vis[root];
        }
        int sum=0;
        if(root->left!=NULL){
            sum+=rob(root->left->left) + rob(root->left->right);
        }
        if(root->right!=NULL){
            sum+=rob(root->right->left) + rob(root->right->right);
        }
        return vis[root]=max(sum+root->val,rob(root->left)+rob(root->right));
    }
};