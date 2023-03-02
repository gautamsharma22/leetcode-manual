#include <bits/stdc++.h> 
bool isSafe(vector < vector < int >> & arr,vector < vector < int >> & visited,int newx,int newy,int row,int col ){
    if(newx<row && newy<col && arr[newx][newy]==1 && visited[newx][newy]==0){
        return true;
    }
    return false;
}
vector<string> ans;
void travel(vector < vector < int >> & arr,vector < vector < int >> & visited,int x,int y,int row,int col){
    string s="";
    //Down
    if(isSafe(arr,visited,x,y+1,row,col )){
        s.push_back('D');
        visited[x][y+1]=1;
        travel(arr,visited,x,y+1,row,col);
        visited[x][y+1]=0;
    }
    //Left
    if(isSafe(arr,visited,x-1,y,row,col )){
        s.push_back('L');
        visited[x-1][y]=1;
        travel(arr,visited,x-1,y,row,col);
        visited[x-1][y]=0;
    }
    //Right
    if(isSafe(arr,visited,x+1,y,row,col )){
        s.push_back('R');
        visited[x+1][y]=1;
        travel(arr,visited,x+1,y,row,col);
        visited[x+1][y]=0;
    }
    //Up
    if(isSafe(arr,visited,x,y-1,row,col )){
        s.push_back('U');
        visited[x][y-1]=1;
        travel(arr,visited,x,y-1,row,col);
        visited[x][y-1]=0;
    }
    if(x==row-1 && y==col-1){
        ans.push_back(s);
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    int row=arr.size();
    int col=arr[0].size();
    int x=0;
    int y=0;
    vector<vector <int>> visited;
    visited=arr;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            visited[i][j]=0;
        }
    }
    travel(arr,visited,x,y,row,col);
    return ans;

}