#include<iostream>
using namespace std;
bool linearSearch(int arr[],int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    return linearSearch(arr + 1, size - 1,key);
}
int main(){
    int arr[5]={2,4,8,8,8};
    bool a = linearSearch(arr, 5,2);
    cout << a;
    return 0;
}
