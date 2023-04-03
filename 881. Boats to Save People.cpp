class Solution
{
public:
    /*
    Approach:
        * Sort the given array.
        * Create a pair of people who have minimum weight + who have maximum weight.
        * If(weight is greater than limit then the people who have max weight will go a boat seperately without any pairing.)
        * If its lesser then we send both of them.
    */
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boat = 0;
        while (left <= right)
        {
            int peopleSiting = people[left] + people[right];
            if (peopleSiting <= limit)
            {
                boat++;
                left++;
                right--;
            }
            else if (peopleSiting > limit)
            {
                right--;
                boat++;
            }
        }
        return boat;
    }
};