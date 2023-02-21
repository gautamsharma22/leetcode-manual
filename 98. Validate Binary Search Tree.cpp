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
    bool validate(TreeNode* root,TreeNode* lower,TreeNode* upper){
        if(root==NULL)return true;
        if((lower && root->val <= lower->val) || (upper && root->val >= upper->val)){
            return false;
        }
            return validate(root->left,lower,root) and validate(root->right,root,upper);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,nullptr,nullptr);
    }
};