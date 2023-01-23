#include <iostream>
using namespace std;
bool issorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    return issorted(arr+1,size-1);
}
int main()
{
    int arr[5]={2,4,8,8,8};
    issorted(arr,5)?cout<<"Sorted":cout<<"Not Sorted";
    
    return 0;
}