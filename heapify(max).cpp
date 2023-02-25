#include <iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr,int n,int i){
    int large=i;
    int left=2*i;
    int right=(2*i)+1;
    if(left<=n && arr[large] < arr[left]){
        large=left;
    }
    if(right <= n && arr[large] < arr[right]){
        large=right;
    }
    if(large != i){
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
    }
}

int main()
{
    vector<int> a{-1,54,53,55,52,50};
    int n=a.size()-1;
    for(int i=n/2;i>=1;i--){
        heapify(a,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}