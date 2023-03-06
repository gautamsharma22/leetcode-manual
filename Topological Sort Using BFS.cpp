#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    vector<int> indegree(v);
	unordered_map<int,list<int>> adj;
	for(int i=0;i<e;i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	for(auto i:adj){
		for(auto j:i.second)
			indegree[j]++;
	}
	queue<int> q;
	for(int i=0;i<v;i++){
		if(indegree[i]==0)q.push(i);
	}
	while(!q.empty()){
		int front=q.front();
		ans.push_back(front);
		q.pop();
		for(auto i:adj[front]){
			indegree[i]--;
			if(indegree[i]==0)q.push(i);
		}
	}
	return ans;
}