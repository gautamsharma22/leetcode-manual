class Solution {
public:
    int uniquePaths_Recursion(int m,int n){
        if(m<0|| n<0) return 0; 
        if(m==0 && n==0)return 1;
        return helper(m,n-1)+helper(m-1,n);;
    }
    int uniquePaths_Memoization(int m,int n,vector<vector<int>> &dp){
        if(m<0|| n<0) return 0; 
        if(m==0 && n==0)return 1;
        if(dp[m][n]!=0)return dp[m][n];
        return dp[m][n]=helper(m,n-1,dp)+helper(m-1,n,dp);;
    }
    int uniquePaths_Tabulation(int m_, int n_) {
        int dp[m_][n_];
        for(int i=0;i<m_;i++)
            dp[i][0]=1;
        for(int i=0;i<n_;i++)
            dp[0][i]=1;
        dp[0][0]=1;
        for(int m=1;m<m_;m++){
            for(int n=1;n<n_;n++){
                int left=dp[m][n-1];
                int bottom=dp[m-1][n];
                dp[m][n]=left+bottom;
            }
        }
        return dp[m_-1][n_-1];
    }
};

/*


----Notes----


----Recursion---

1. Start from m-1 n-1.
2. Go one step up + Go one step left
3. If reached top Return 1;

----Tabulation---

1. Start from 1,1.

2.Initialize first row && first column with 1's ( Cause if the destination is in same row and same column then only possible way will be one.)

2. Add Values of one step up +  one step left cause ( There were only two prev choices from where u have came either top or left)

3. Return DP[m-1][n-1] (-1 for zero based indexing);

Additional notes:-

* - Similar as previous question Minimum Path Sum (Leetcode 64)

*/