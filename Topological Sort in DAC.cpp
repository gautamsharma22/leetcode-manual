#include <bits/stdc++.h> 
void ts(int node,vector<int> &ans,vector<vector<int>> &adj,vector<bool> &visited){
	visited[node]=true;
	for(auto i:adj[node]){
		if(!visited[i]){
			ts(i,ans,adj,visited);
		}
	}
	ans.insert(ans.begin(),node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
	vector<vector<int>> adj(v);
	vector<bool> visited(v);
	for(int i=0;i<e;i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	for(int i=0;i<v;i++){
		if(!visited[i]){
			ts(i,ans,adj,visited);
		}
	}
	return ans;
}