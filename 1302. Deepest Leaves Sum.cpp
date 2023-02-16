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
int left=0,right=0;
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                sum+=temp->val;
            }
        }
        return sum;
    }
};