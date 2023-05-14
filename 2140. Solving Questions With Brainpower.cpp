class Solution
{
public:
    // int helper(vector<vector<int>>& questions,int index){
    //     if(index>=questions.size())return 0;
    //     int nottake=helper(questions,index+1);
    //     int take=questions[index][0]+helper(questions,index+questions[index][1]+1);
    //     return max(take,nottake);
    // }
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long> dp(questions.size() + 1, 0);
        int n = questions.size();
        dp[n - 1] = questions[n - 1][0];
        for (int index = n - 2; index >= 0; index--)
        {
            long long nottake = dp[index + 1];
            long long take = 0;
            int next = index + questions[index][1] + 1;
            take = questions[index][0] + (next < n ? dp[next] : 0);
            dp[index] = max(take, nottake);
        }
        return dp[0];
    }
};