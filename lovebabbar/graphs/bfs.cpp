vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.
    // Use a DS to keep track of whether node/vertex is visited or not
    vector<bool> visited(n, false);
    // Use a DS to perform BFS
    queue<int> q;

    // The first node/vertex is 0 so push it to queue
    q.push(0);

    // Create a vector to store the answer
    vector<int> ans;

    while (!q.empty())
    {                               // while queue is not empty
        int front_node = q.front(); // store the front_node
        q.pop();                    // remove the element fromt queue once stored in front_node

        // mark the front_node as visited
        visited[front_node] = true;

        // add visited node to ans vector
        ans.push_back(front_node);

        // loop over all the neighbouring elements of the visited node
        for (int i = 0; i < adj[front_node].size(); i++)
        {
            // push all the neighbouring nodes into the queue
            // mark visited to save time
            if (!visited[adj[front_node][i]])
            {
                q.push(adj[front_node][i]);
                visited[adj[front_node][i]] = true;
            }
        }
    }
    return ans;
}