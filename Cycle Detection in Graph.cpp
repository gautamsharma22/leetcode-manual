#include<iostream>
#include<unordered_map>
#include<list>
bool iscycleDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> adj){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycle=iscycleDFS(neighbour,node,visited,adj);
            if(cycle)return true;
        }else if(neighbour!=parent)return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool cycle=iscycleDFS(i,-1,visited,adj);
            if(cycle)return "Yes";
        }
    }
    return "No";
}
