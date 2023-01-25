class Solution {
public:
 void subset(vector<vector<int>>& MainAns,int index,vector<int> ans,vector<int> nums){
     if(index>=nums.size()){
         MainAns.push_back(ans);
         return;
     }
     subset(MainAns,index+1,ans,nums);
     ans.push_back(nums[index]);
     subset(MainAns,index+1,ans,nums);

 }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> MainAns;
        vector<int> ans;
        int index=0;
        subset(MainAns,index,ans,nums);
        return MainAns;
    }
};