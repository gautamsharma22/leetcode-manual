class Solution {
public:
    void permutation(vector<vector<int>>& MainAns, int index,vector<int> nums){
        if(index>=nums.size()){
            MainAns.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permutation(MainAns,index+1,nums);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> MainAns;
        int index=0;
        permutation(MainAns,index,nums);
        return MainAns;
    }
};