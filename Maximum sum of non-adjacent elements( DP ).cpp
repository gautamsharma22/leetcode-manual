#include<iostream>
#include<vector>
using namespace std;
int totalsum=0;
//Normal recursion (Gives TLE)
int helper(vector<int> nums,int i,int size){
    if(i>size)return 0;
    if(i==size)return nums[i];
    //Include
    int include=helper(nums,i+2,size)+nums[i];
    int exclude=helper(nums,i+1,size)+0;
    //Exclude
    return max(include,exclude);
}
//Recursion with Memoization (Gives TLE)
int helper2(vector<int> nums,int i,int size,vector<int> &dp){
    if(i>size)return 0;
    if(i==size)return nums[i];
    if(dp[i]!=-1)return dp[i];
    //Include
    int include=helper(nums,i+2,size)+nums[i];
    //Exclude
    int exclude=helper(nums,i+1,size)+0;
    dp[i]=max(include,exclude);
    return dp[i];
}
//Tabulation (Accepted)
int helper3(vector<int> nums){
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        int include=nums[i]+dp[i-2];
        int exclude=0+dp[i-1];
        dp[i]=max(include,exclude);
    }
    return dp[n-1];
} 
//Fine Tuning
int helper4(vector<int> nums){
    int n=nums.size();
    int prev1=nums[0];
    int prev2=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        int include=nums[i]+prev1;
        int exclude=0+prev2;
        prev1=prev2;
        prev2=max(include,exclude);
    }
    return prev2;
} 
int main(){
    vector<int> nums{1, 2, 3, 1, 3, 5, 8 ,1 ,9};
    cout<<helper(nums,0,nums.size()-1);
    return 0;
}
