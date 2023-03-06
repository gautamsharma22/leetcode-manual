#include <bits/stdc++.h> 
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  int count=0;
  vector<int> indegree(n);
vector<vector<int>> adj(n);
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first-1;
		int v=edges[i].second-1;
		adj[u].push_back(v);
	}
	for(auto i:adj){
		for(auto j:i)
			indegree[j]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[i]==0)q.push(i);
	}
	while(!q.empty()){
		int front=q.front();
		count++;
		q.pop();
		for(auto i:adj[front]){
			indegree[i]--;
			if(indegree[i]==0)q.push(i);
		}
	}
  return (count!=n);
}
