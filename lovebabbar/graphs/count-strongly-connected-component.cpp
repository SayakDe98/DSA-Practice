#include<bits/stdc++.h>
void dfs(int node, unordered_map<int, bool>& vis, stack<int>& st, unordered_map<int, list<int>>& adj) {
	vis[node] = true;
	for(auto neighbour: adj[node]) {
		if(!vis[node]) {
			dfs(neighbour, vis, st, adj);
		}
	}
	st.push(node);//topo sort logic
}

void revDfs(int node, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adj) {
	vis[node] = true;
	for(auto neighbour: adj[node]) {
		if(!vis[neighbour]) {
			revDfs(neighbour, vis, adj);
		}
	}	
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	//adjacency list
	unordered_map<int, list<int>> adj;
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	//topo sort
	stack<int> st;
	unordered_map<int, bool> vis;
	for(int i = 0; i < v; i++) {
		if(!vis[i]) {
			dfs(i, vis, st, adj);
		}
	}

	//Create transpose graph
	unordered_map<int, list<int>> transpose;
	for(int i = 0; i < v; i++) {
		vis[i] = false;//since visited got updated while doing dfs so revert that
		for(auto neighbour: adj[i]) {
			transpose[neighbour].push_back(i);
		}
	}

	//dfs call using above ordering
	int count = 0;
	while(!st.empty()) {
		int top = st.top();
		st.pop();
		if(!vis[top]) {
			count++;
			revDfs(top, vis, transpose);
		}
	}
	return count;
}