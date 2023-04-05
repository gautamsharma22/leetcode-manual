class Solution
{
public:
    // Below is the function from Largest area in histogram which provides maximum area by taking heights array.
    vector<int> nextSmallerElement(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> next;
        vector<int> prev;
        next = nextSmallerElement(heights);
        prev = prevSmallerElement(heights);
        int maxarea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int length = heights[i];
            if (next[i] == -1)
                next[i] = heights.size();
            int width = next[i] - prev[i] - 1;
            int area = length * width;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
    /*
    Approach :
    To solve this we have to just convert this problem to largest Area in histogram Problem.
    Everything is same (bars logic added).
    */
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix[0].size();
        vector<int> bars(m, 0);
        int maxarea = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    bars[j] += 1; // Instaed of creating bars every time we just update the value;
                }
                else
                {
                    bars[j] = 0; // Means we have to reset the bar.
                }
            }
            int area = largestRectangleArea(bars);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};