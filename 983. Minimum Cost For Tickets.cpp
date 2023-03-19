int helperRec(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    if (index >= days.size())
        return 0;
    int cost1 = costs[0] + helperRec(days, costs, index + 1, dp);
    int dayCovered = index;
    while (dayCovered < days.size() and days[dayCovered] < days[index] + 7)
    {
        dayCovered++;
    }
    int cost2 = costs[1] + helperRec(days, costs, dayCovered, dp);
    while (dayCovered < days.size() and days[dayCovered] < days[index] + 30)
    {
        dayCovered++;
    }
    int cost3 = costs[2] + helperRec(days, costs, dayCovered, dp);
    return min(cost1, min(cost2, cost3));
}
int helperMem(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    if (index >= days.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int cost1 = costs[0] + helperMem(days, costs, index + 1, dp);
    int dayCovered = index;
    while (dayCovered < days.size() and days[dayCovered] < days[index] + 7)
    {
        dayCovered++;
    }
    int cost2 = costs[1] + helperMem(days, costs, dayCovered, dp);
    while (dayCovered < days.size() and days[dayCovered] < days[index] + 30)
    {
        dayCovered++;
    }
    int cost3 = costs[2] + helperMem(days, costs, dayCovered, dp);
    return dp[index] = min(cost1, min(cost2, cost3));
}
int helperTab(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int cost1 = costs[0] + dp[i + 1];
        int dayCovered = i;
        while (dayCovered < days.size() and days[dayCovered] < days[i] + 7) // Check if the day was covered in previous package or not
        {
            dayCovered++;
        }
        int cost2 = costs[1] + dp[dayCovered];
        while (dayCovered < days.size() and days[dayCovered] < days[i] + 30)
        {
            dayCovered++;
        }
        int cost3 = costs[2] + dp[dayCovered];
        dp[i] = min(cost1, min(cost2, cost3));
    }
    return dp[0];
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    // vector<int> dp(days.size()+1,-1);
    // return helperRec(days,costs,0);
    // return helperMem(days,costs,0,dp);
    // return helperTab(days,costs);
}