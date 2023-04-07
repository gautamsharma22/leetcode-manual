//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> times;
        for (int i = 0; i < n; i++)
        {
            times.push_back({start[i], end[i]});
        }

        sort(times.begin(), times.end(), comp);
        int totalMeetings = 1;
        int lastMeetingEnd = times[0].second;
        for (int i = 1; i < n; i++)
        {
            if (times[i].first > lastMeetingEnd)
            { // Currrent Meeting starting time should be less than last meeting ending time
                totalMeetings++;
                lastMeetingEnd = times[i].second;
            }
        }
        return totalMeetings;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends