void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    // store node in component
    component.push_back(node);

    visited[node] = true; // mark node as visited

    // recursive call for all nodes
    for (auto i : adj[node])
    {
        if (!visited[i])
        { // if node is not visited do DFS traversal
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    // prepare an adjacency list

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // push them in adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // create a 2d vector to store ans
    vector<vector<int>> ans;

    // create a Data Structure(DS) to keep track of node visited or not
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    { // loop over all components
        if (!visited[i])
        { // if node is not visited do DFS traversal
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component); // push component in ans
        }
    }
    return ans;
}