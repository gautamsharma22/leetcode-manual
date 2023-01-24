#include<iostream>
using namespace std;
int power(int a , int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans = power(a, b / 2);
    if(b%2==0){
        return ans * ans;
    }else{
        
        return a * ans * ans;
    }
}
int main()
{
    int a = 3;
    int b = 1;
    int x=power(a, b);
    cout << x;
    return 0;
}