#include <bits/stdc++.h> 
bool isSafe(vector < vector < int >> & arr,vector < vector < bool >> & visited,int newx,int newy,int n ){
    if(( newx>=0 && newx<n) && ( newy>=0 && newy<n) && arr[newx][newy]==1 && visited[newx][newy]==0){
        return true;
    }
    return false;
}
void travel(vector<string> &ans,vector < vector < int >> & arr,vector < vector < bool >> & visited,int x,int y,int n,string s){

    if(x==n-1 && y==n-1){
        ans.push_back(s);
        return;
    }
    visited[x][y]=1;
    //Down
    if(isSafe(arr,visited,x+1,y,n)){
        travel(ans,arr,visited,x+1,y,n,s+'D');
    }
    //Left
    if(isSafe(arr,visited,x,y-1,n)){
        travel(ans,arr,visited,x,y-1,n,s+'L');
    }
    //Right
    if(isSafe(arr,visited,x,y+1,n)){
        travel(ans,arr,visited,x,y+1,n,s+'R');
    }
    //Up
    if(isSafe(arr,visited,x-1,y,n)){
        travel(ans,arr,visited,x-1,y,n,s+'U');
    }
    visited[x][y]=0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    string s="";
    vector<string> ans;
    if(arr[0][0]==0)return ans;
    vector<vector <bool>> visited(n ,vector<bool> (n,0));
    travel(ans,arr,visited,0,0,n,s);
    return ans;

}