class Solution {
public:
// 1st approach
    int countOdds(int low, int high) {
        if(high%2==0 && low%2==0){
            return (high-low)/2;
        }
        else if( (high%2==0 && low%2!=0) || (high%2!=0 && low%2==0)){
            return ((high-low-1)/2)+1;
        }
        else{
            return ( (high-low-2) )/2+2;
        }
    }
};
// tried to optimize a little bit :)
class Solution {
public:
    int countOdds(int low, int high) {
        if( (high%2==0 && low%2!=0) || (high%2!=0 && low%2==0) || (high%2!=0 && low%2!=0)){
            return ((high-low)/2)+1;
        }else{
            return (high-low)/2;
        }
    }
};