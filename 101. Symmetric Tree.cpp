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
class Solution_ {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            auto left=st.top();
            st.pop();
            auto right=st.top();
            st.pop();
            if(left==nullptr && right==nullptr)continue;
            if(left==nullptr || right==nullptr || left->val!=right->val)return false;
            st.push(left->left);
            st.push(right->right);
            st.push(left->right);
            st.push(right->left);
        }
        return true;
    }
};
class Solution {
public:
    bool helper(TreeNode* l,TreeNode* r){
        if(!l && !r)return true;
        if(!l || !r || l->val!=r->val)return false;
        return helper(l->left,r->right) && helper(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};