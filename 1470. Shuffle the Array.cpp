class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> numbers;
        int x=n;
        for(int i=0;i<n;i++){
            numbers.push_back(nums[i]);
            numbers.push_back(nums[x++]);
        }
        return numbers;
    }
};