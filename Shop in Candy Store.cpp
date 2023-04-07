//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // For minimum cost.
        int start = 0;
        int end = N - 1;
        int totalMinCost = 0;
        sort(candies, candies + N);
        while (start <= end)
        {
            totalMinCost += candies[start]; // Buy candies from start.
            start++;
            end = end - K; // Take Free Candies From End.
        }

        // For maximum cost.
        start = 0;
        end = N - 1;
        int totalMaxCost = 0;
        sort(candies, candies + N);
        while (start <= end)
        {
            totalMaxCost += candies[end]; // Buy candies frrom end.
            end--;
            start = start + K; // Take free candies from start.
        }
        return {totalMinCost, totalMaxCost};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends