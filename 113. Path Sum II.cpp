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
    vector<vector<int>> ans;
    vector<int> path;
    void helper(TreeNode* root,int target){
        if(root==NULL)
            return;
        path.push_back(root->val);
        if(root->left)
            helper(root->left,target);
        if(root->right)
            helper(root->right,target);
        int sum=0;
        if(root->left==NULL && root->right==NULL){
            for(int i=0;i<path.size();i++){
                sum+=path[i];
            }
            if(sum==target){
                ans.push_back(path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum);
        return ans;
    }
};