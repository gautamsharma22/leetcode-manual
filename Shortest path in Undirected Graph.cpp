vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	vector<vector<int>> adj(n+1);
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
   	vector<int> parent(n+1);
   	vector<bool> visited(n+1);
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(auto i:adj[front]){
			if(!visited[i]){
				visited[i]=true;
				parent[i]=front;
				q.push(i);
			}
		}
	}
	vector<int> ans;
	int destination=t;
	ans.push_back(destination);
	while(destination!=s){
		destination=parent[destination];
		ans.push_back(destination);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
