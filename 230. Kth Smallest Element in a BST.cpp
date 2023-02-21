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
int helper(TreeNode* root, int k,int &i){
    if(root==NULL){
        return -1;
    }
    int left=helper(root->left,k,i);
    if(left!=-1)return left;
        i++;
    if(k==i)return root->val;
    return helper(root->right,k,i);
    // return -1;
}
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return helper(root,k,i);
    }
};