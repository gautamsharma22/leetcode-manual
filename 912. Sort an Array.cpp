class Solution {
public:
        void merge(vector<int> &nums,int lower,int mid,int upper){
        vector<int> temp(upper - lower + 1);
        int i = lower, j = mid + 1, k = 0;
        while (i <= mid && j <= upper) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= upper) {
            temp[k++] = nums[j++];
        }
        for (int p = 0; p < k; p++) {
            // cout<<"Lower : "<<lower<<" + P : "<<p<<" \n";
            nums[lower + p] = temp[p];
        }
    }
    void helper(vector<int>& nums, int lower,int upper){
        if(lower>=upper)return;
        int mid=(lower+upper)/2;
        helper(nums,lower,mid);
        helper(nums,mid+1,upper);
        merge(nums,lower,mid,upper);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        int upper=nums.size()-1;
        helper(nums,0,upper);
        return nums;
    }
};