class Solution
{
public:
    /*
        Approach: Using Union Find to Count Groups.

        * Word 1 and Word 2 belong to same groups if diffrence of their character is at most 2.(TestCases are are provide such that two strings are anagram of each other.)
        * We'll group the words Using Union;
        * Classic Implementation of Union functions (Here I have ignored Rank of the unions but it's recommended for better time complexity);


    */
    int parent[301];
    int findParent(int &a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = findParent(parent[a]); // Compressed Path
    }
    bool makeunion(int &i, int &j)
    {
        int x = findParent(i);
        int y = findParent(j);
        if (x == y)
            return false;
        else
            parent[y] = x;
        return true;
    }
    bool Similar(string &word1, string &word2)
    {
        int count = 0;
        for (int i = 0; i < word1.size(); i++)
        {
            if (word1[i] != word2[i])
            {
                count++;
            }
            if (count > 2)
                return false;
        }
        return (count <= 2);
    }
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int group = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string word1 = strs[i];
                string word2 = strs[j];
                if (Similar(word1, word2) && makeunion(i, j))
                {
                    group--;
                }
            }
        }
        return group;
    }
};