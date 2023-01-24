#include<iostream>
using namespace std;
bool binarySearch(int arr[],int start,int end,int key){
    if(start>end){
        return false;
    }
    int mid = (start + end) / 2;
    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]>key)
    {
        end = mid-1;
        return binarySearch(arr,start, end,key);
    }
    if(arr[mid]<key)
    {
        start = mid + 1;
        return binarySearch(arr,start, end,key);
    }
    return true;
}
int main(){
    int arr[5]={2,4,8,8,8};
    bool a = binarySearch(arr, 0,4,0);
    cout << a;
    return 0;
}
