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
/*
    Approach 1

    TC->O(N)
    SC->O(1)

(    A move is valid is if last move was right next move will be left and if last move was left next move will be right.)

    * Standing at Current Node we have two options (Left or Right)
    * If Left is Valid we Increase Count By 1.(And make a call for Left)
    * If Left is Valid but we are going right we reset count to 1.(And make a call for Right)

    * If Right is Valid we Increase Count By 1.(And make a call for Right)
    * If Right is Valid but we are going Left we reset count to 1.(And make a call for Left)


*/
    int ans=0;
    void helper(TreeNode* root,bool canMoveLeft,int currLen){
        if(root==NULL)return;
        ans=max(ans,currLen);
        if(canMoveLeft){
            helper(root->left,!canMoveLeft,currLen+1);
            helper(root->right,canMoveLeft,1);
        }else{
            helper(root->left,canMoveLeft,1);
            helper(root->right,!canMoveLeft,currLen+1);
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        helper(root,false,0);
        helper(root,true,0);
        return ans;
    }
};