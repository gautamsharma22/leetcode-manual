/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int sumArr(int arr[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int sum = arr[0] + arr[1];
    int total = sum + sumArr(arr + 2, size-2);
    return total;
}
int main()
{
    int arr[13]={2,4,8,8,8,67,7,8,5,5,655,35,34};
    int sum=sumArr(arr, 13);
    cout<<sum;
    return 0;
}
