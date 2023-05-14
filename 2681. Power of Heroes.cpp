#define ll long long
class Solution {
public:
    // int ans=0;
    long long const MOD=1e9 + 7;
    // void helper(vector<int>& nums,int index,vector<int> arr){
    //     if(index>nums.size())return;
    //     if(!arr.empty()){   
    //     long long mini=*min_element(arr.begin(), arr.end());
    //     long long maxi=*max_element(arr.begin(), arr.end());
    //     long long power=(maxi*maxi)*mini;
    //         ans=(ans)%MOD+power;
    //     }
    //     for(int i=index;i<nums.size();i++){
    //         arr.push_back(nums[i]);
    //         helper(nums,i+1,arr);
    //         arr.pop_back();
    //     }
    //     return;
    // }
    // int sumOfPower(vector<int>& nums) {
    //     vector<int> arr;
    //     helper(nums,0,arr);
    //     return ans;
    // }
    long long power(long long x,long long y){
        long long res=1;
        while(y--){
            res=(res*x)%MOD;
        }
        return res;
    }
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        ll pre=0;
        ll sum=0;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            sum=(sum+(long long)power(i,3)%MOD);
            sum=(sum+(long long)power(i,2)*pre)%MOD;
            pre=(pre*2+i)%MOD;
        }
        return sum;
        
    }
};