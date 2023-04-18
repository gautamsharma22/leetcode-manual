class Solution {
public:
/*
    Intuition :-> 
    Missing number will be in the range of 1- N (N=size of nums+1).

    TC-> O(N) 
    SC-> O(N)

*/
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> ans(nums.size()+1,false);
        int n=nums.size();
        for(auto a:nums){
            if(a<=n && a>=0){
                ans[a]=true;
            }
        }
        for(int i=1;i<ans.size();i++){
            if(!ans[i]){
                return i;
            }
        }
        return n+1;
    }
/*
    Approach 2:-

    TC-> O(N) 
    SC-> O(1)
    Instead of using hashset we can store the value in modifying the input array.

*/
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int CurrentElement=nums[i];
            if(CurrentElement>0 && CurrentElement<n){  
                int ExpectedPosition=CurrentElement-1;
                if(nums[ExpectedPosition]!=CurrentElement){ // Means any other element is present there.
                    swap(nums[ExpectedPosition],nums[i]);
                    i--; // To again check if the swapped element is at current position or not.
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;

    }
};