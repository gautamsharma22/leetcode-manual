// Using resursive method Day 1 (Recursion)
class Solution {
public:
    int fib(int n) {
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        int sum=0;
        return sum+=fib(n-1)+fib(n-2);
    }
};