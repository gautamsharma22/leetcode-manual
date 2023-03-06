#include <bits/stdc++.h> 
void ts(int node,stack<int> &s,unordered_map<int,list<int>> &adj,vector<bool> &visited){
	visited[node]=true;
	for(auto i:adj[node]){
		if(!visited[i]){
			ts(i,s,adj,visited);
		}
	}
	s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
	unordered_map<int,list<int>> adj;
	vector<bool> visited(v); 
	stack<int> s;
	for(int i=0;i<e;i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	for(int i=0;i<v;i++){
		if(!visited[i]){
			ts(i,s,adj,visited);
		}
	}

	while(!s.empty()){
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}