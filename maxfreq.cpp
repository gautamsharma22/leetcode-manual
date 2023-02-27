#include<iostream>
#include<vector>
#include<map>
using namespace std;
int maximumFrequency(vector<int> &arr)
{
    //Write your code here
    map<int,int> mp;
    int maxFreq=0;
    int ans = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]] > maxFreq)maxFreq=mp[arr[i]];
    }
    for(int i=0;i<arr.size();i++){
        if(mp[arr[i]] == maxFreq){
            ans = arr[i];
            break;
        }

    }
    return ans;

}
int main(){
    vector<int> arr{4 ,-5 ,1};
    cout<<maximumFrequency(arr);
    return 0;
}