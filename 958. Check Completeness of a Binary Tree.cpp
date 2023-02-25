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
int count(TreeNode* root){
    if (root==NULL)return 0;
    int ans=1+count(root->left)+count(root->right);
    return ans;
}
bool helper(TreeNode* root,int i,int count){
    if(root==NULL){
        return true;
    }
    if(i>=count){
        return false;
    }else{
        bool left=helper(root->left,2*i+1,count);
        bool right=helper(root->right,2*i+2,count);
        return left && right;
    }
}
    bool isCompleteTree(TreeNode* root) {
        int c=count(root);
        return helper(root,0,c);
    }
};