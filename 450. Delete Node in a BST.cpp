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
    int minValue(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val==key){
            if(!root->left && !root->right){
                delete(root);
                return nullptr;
            }
            if(root->left && !root->right){
                TreeNode* temp=root->left;
                return temp;
            }
            if(!root->left && root->right){
                TreeNode* temp=root->right;
                return temp;
            }
            if(root->left && root->right){
                int min=minValue(root->right);
                root->val=min;
                root->right=deleteNode(root->right,min);
                return root;
            }
            
        }else if(root->val > key ){
            root->left=deleteNode(root->left,key);
            return root;
        }else{
            root->right=deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};