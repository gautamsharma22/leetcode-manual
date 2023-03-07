class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=0,high=1e14;
        while(low<=high){
            long long mid=(high+low)>>1;
            long long count=0;
            for(auto i:time){
                count=count+(mid/i);
                if(count>=totalTrips)break;
            }
            if(count>=totalTrips){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};