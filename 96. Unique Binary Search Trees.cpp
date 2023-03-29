class Solution
{
public:
    // int helper(int n){
    //     if(n<=1)return 1;
    //     int ans=0;
    //     for(int i=1;i<=n;i++){
    //         int left=helper(i-1);
    //         int right=helper(n-i);
    //         ans+=left*right;
    //     }
    //     return ans;
    // }
    // int numTrees(int n) {
    //     return helper(n);
    // }
    int helper(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int left = helper(i - 1, dp);
            int right = helper(n - i, dp);
            ans += left * right;
        }
        return dp[n] = ans;
    }
    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};