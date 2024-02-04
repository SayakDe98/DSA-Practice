#include <bits/stdc++.h>
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2]; // ascending order of sorting according to weights
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i; // each node is parent of itself at begin
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]); // we are attaching the node with the parent after finding it. This
    // betters the speed of the program
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // find respective parents
    u = findParent(parent, u);
    v = findParent(parent, v);

    // find rank of u and v compare them and update parent and rank accordingly
    if (rank[u] < rank[v])
    {
        parent[u] = v;
        // rank[v]++;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
        // rank[u]++;
    }
    else
    {
        // make v a parent of u or u a parent of v works either ways, but follow a convention
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    /*
      Don't write main().
      Don't read input, it is passed as function argument.
      No need to print anything.
      Taking input and printing output is handled automatically.
    */
    sort(edges.begin(), edges.end(), cmp); // sort according to weights, O(nlogm) where m is no of edges

    // For disjoin set create parent and rank DS and initialize them
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    // for min spanning tree starting weight = 0
    int minWeight = 0;

    // iterate over all the edges
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v)
        {                                 // if parents are different
            minWeight += wt;              // add the weight to minWeight
            unionSet(u, v, parent, rank); // find their unionSet/merge into single graph, O(1) mostly
        }
    }
    return minWeight; // Therefore overall TC: O(nlogm), SC: O(n)
}