int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;  // we start from 1 instead of 0
        int v = edges[i].second - 1; // we start from 1 instead of 0

        // directed graph
        adj[u].push_back(v);
    }

    // find all the indegrees
    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q; // queue for dfs
    // push 0 indegrees into queue
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    int count = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return count == n ? false : true; // if it is valid TS then number of nodes will be equal to n else false
}