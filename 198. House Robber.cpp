// Very Easy (Depends you take current element or you don't)

//Recursion (Gives TLE)
class Solution1 {
public:
int helper2(vector<int> nums,int i,int size){
    if(i>size)return 0;
    if(i==size)return nums[i];
    //Include
    int include=helper2(nums,i+2,size)+nums[i];
    //Exclude
    int exclude=helper2(nums,i+1,size)+0;
    
    return max(include,exclude);
} 
    int rob(vector<int>& nums) {
        int n=nums.size();
        return helper2(nums,0,n-1);
    }
};


//Recursion with memoization(Accepted)
class Solution2 {
public:
    int helper2(vector<int> nums,int i,int size,vector<int> &dp){
        if(i>size)return 0;
        if(i==size)return nums[i];
        if(dp[i]!=-1)return dp[i];
        //Include
        int include=helper2(nums,i+2,size,dp)+nums[i];
        //Exclude
        int exclude=helper2(nums,i+1,size,dp)+0;
        dp[i]=max(include,exclude);
        return dp[i];
    } 
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper2(nums,0,n-1,dp);
    }

};


//Tabulation Bottoms Up
class Solution3 {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            int include=nums[i]+dp[i-2];
            int exclude=0+dp[i-1];
            dp[i]=max(include,exclude);
        }
        return dp[n-1];
    }
};

//Fine Tuning with the help of prev sol
class Solution4{
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 0; i < n; i++)
        {
            int include=nums[i]+prev1;
            int exclude=0+prev2;
            prev1=prev2;
            prev2=max(include,exclude);
        }
        return prev2;
    }
};