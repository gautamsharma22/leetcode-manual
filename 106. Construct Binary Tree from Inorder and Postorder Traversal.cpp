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
    int find(vector<int> inorder,int key){
        for(int i=0;i<inorder.size();i++){
            if(key==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,int inorderStart,int inorderEnd,int start,int &index){
        if(index>start || inorderStart>inorderEnd){
            return NULL;
        }
        int rootvalue=postorder[index--];
        int x=find(inorder,rootvalue);
        TreeNode* root=new TreeNode(rootvalue);
        root->right=helper(postorder,inorder,x+1,inorderEnd,start,index);
        root->left=helper(postorder,inorder,inorderStart,x-1,start,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size()-1;
        int index=size;
        TreeNode* root=helper(postorder,inorder,0,size,size,index);
        return root;
    }
};