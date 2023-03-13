#include<iostream>
#include<vector>
using namespace std;
int totalsum=0;
int helper(vector<int> nums,int i,int size){
    if(i>size)return 0;
    if(i==size)return nums[i];
    //Include
    int include=helper(nums,i+2,size)+nums[i];
    int exclude=helper(nums,i+1,size)+0;
    //Exclude
    return max(include,exclude);
}
int main(){
    vector<int> nums{1, 2, 3, 1, 3, 5, 8 ,1 ,9};
    cout<<helper(nums,0,nums.size());
    return 0;
}
