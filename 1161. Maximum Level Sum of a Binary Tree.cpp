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
    int maxLevelSum(TreeNode* root) {
        int max=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        int index=0;
        int index1=0;
        while(!q.empty()){
            index1++;
            sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                sum+=temp->val;
            }
            if(sum>max){
                max=sum;
                index=index1;
            }
        }
        return index;
    }
};