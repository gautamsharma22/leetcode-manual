//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        int sundays = S / 7;
        int eligibleDays = S - sundays; // Days I can buy food.
        int totalFoodRequired = M * S;  // Total Food required.
        int ans = 0;
        if (totalFoodRequired % N == 0)
        {
            ans = totalFoodRequired / N;
        }
        else
        {
            ans = totalFoodRequired / N + 1; // Remaing food to be buyed on the next day.
        }
        if (ans <= eligibleDays)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends