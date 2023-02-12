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
    vector<vector<int>> zigzag;
    void traverse(TreeNode* root){
        if(!root){
            return;
        }
        bool x=false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> ans;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp!=NULL){
                    q.push(temp->left);
                    q.push(temp->right);
                    ans.push_back(temp->val);
                }
            }
            if(x){
                reverse(ans.begin(),ans.end());
            }
            x=!x;
            if(!ans.empty()){
                zigzag.push_back(ans);
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root);
        return zigzag;
    }
};