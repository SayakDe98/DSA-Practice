// #include <unordered_map>
// #include <list>
// #include <queue>
// bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
// {
//     unordered_map<int, int> parent; // key is the node and value is parent

//     parent[src] = -1; // since we just entered a new component so dont know src node's parent
//     visited[src] = 1; // mark src as visited
//     queue<int> q;
//     q.push(src); // push src into queue

//     while (!q.empty())
//     {
//         int front = q.front(); // get front node
//         q.pop();               // pop the top of queue

//         for (auto neighbour : adj[front])
//         { // find all neighbours of adj list's front node
//             if (visited[neighbour] == true && neighbour != parent[front])
//                 return true; // we found the cycle we were looking for. the neighbour is visited and the neighbour is not parent of front node
//             else if (!visited[neighbour])
//             {
//                 q.push(neighbour);         // push the neighbour into queue
//                 visited[neighbour] = 1;    // mark neighbour as visited
//                 parent[neighbour] = front; // update the parent to the front of queue
//             }
//         }
//     }
//     return false;
// }

// string cycleDetection(vector<vector<int>> &edges, int n, int m)
// {
//     // Write your code here.
//     // Create adjacency list
//     unordered_map<int, list<int>> adj;
//     for (int i = 0; i < m; i++)
//     {
//         int u = edges[i][0]; // first vertex
//         int v = edges[i][1]; // second vertex

//         // undirected graph so edges in both sides, let's push all the neighbours
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     unordered_map<int, bool> visited;
//     // to handle disconnected component:
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])//if component is not visited
//         {
//             bool ans = isCyclicBFS(i, visited, adj);
//             if (ans)
//                 return "Yes"; // cycle found
//         }
//     }
//     return "No"; // cycle not found
// }

#include <unordered_map>
#include <list>
#include <queue>
bool isCyclic(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    // Create a parent DS
    unordered_map<int, int> parent; // key=child, value=parent
    parent[src] = -1;               // starting node has parent of -1 always
    visited[src] = 1;               // mark src node as visited
    queue<int> q;                   // Create a DS to store the nodes for DFS and getting front of queue
    q.push(src);                    // Push the parent into queue

    while (!q.empty())
    {
        int front = q.front(); // store the front of queue into front variable
        q.pop();               // pop the front of queue, since we stored it in front and will find all its neighbours and the parent needs to be updated

        for (auto neighbour : adj[front]) // we are checking all the neighbours of front
        {
            if (visited[neighbour] == 1 && neighbour != parent[front])
            {                // if neighbour is already visited and it is not a parent of front
                return true; // we found the cycle
            }
            else if (!visited[neighbour])
            {                              // if neighbour is not visited
                q.push(neighbour);         // push neighbour to queue
                visited[neighbour] = 1;    // mark neighbour as visited
                parent[neighbour] = front; // make front the parent of neighbour
            }
            // neglect if neighbour is visited and is a parent of front node for which we are
            //  checking neighbours
        }
    }
    return false; // cycle not found
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) // add neighbours in adj list
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // undirected graph so u and v both are neighbours of each other
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create a visited Data Structure
    unordered_map<int, bool> visited;

    // loop over all the disconnected components of graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {                                         // if component is not visited
            bool ans = isCyclic(i, visited, adj); // if cycle is found for current component
            if (ans)                              // cycle exists for current component
                return "Yes";
        }
    }
    return "No";
}

// BFS:
#include <unordered_map>
#include <list>
#include <queue>
// bool isCyclic(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
//     //Create a parent DS
//     unordered_map<int, int> parent;//key=child, value=parent
//     parent[src] = -1;//starting node has parent of -1 always
//     visited[src] = 1;//mark src node as visited
//     queue<int> q;//Create a DS to store the nodes for DFS and getting front of queue
//     q.push(src);//Push the parent into queue

//     while(!q.empty()) {
//         int front = q.front();//store the front of queue into front variable
//         q.pop();//pop the front of queue, since we stored it in front and will find all its neighbours and the parent needs to be updated

//         for(auto neighbour: adj[front]) {//we are checking all the neighbours of front
//             if(visited[neighbour] == 1 && neighbour != parent[front]) {//if neighbour is already visited and it is not a parent of front
//                 return true;//we found the cycle
//             } else if(!visited[neighbour]) {//if neighbour is not visited
//                 q.push(neighbour);//push neighbour to queue
//                 visited[neighbour] = 1;//mark neighbour as visited
//                 parent[neighbour] = front;//make front the parent of neighbour
//             }
//             //neglect if neighbour is visited and is a parent of front node for which we are
//             // checking neighbours
//         }
//     }
//     return false;//cycle not found
// }

// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     // Write your code here.
//     //Create adjacency list
//     unordered_map<int, list<int>> adj;
//     for(int i = 0; i < m; i++) {//add neighbours in adj list
//         int u = edges[i][0];
//         int v = edges[i][1];

//         //undirected graph so u and v both are neighbours of each other
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     //Create a visited Data Structure
//     unordered_map<int, bool> visited;

//     //loop over all the disconnected components of graph
//     for(int i = 0; i < n; i++) {
//         if(!visited[i]) { //if component is not visited
//             bool ans = isCyclic(i, visited, adj);//if cycle is found for current component
//             if(ans)//cycle exists for current component
//                 return "Yes";
//         }
//     }
//     return "No";
// }

// DFS
bool isCyclic(int src, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[src] = 1; // src is visited
    for (auto neighbour : adj[src])
    {
        if (!visited[neighbour])
        {
            bool cyclePresent = isCyclic(neighbour, src, adj, visited);
            if (cyclePresent)
                return true;
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0]; // first vertex
        int v = edges[i][1]; // second vertex

        // add the neighbours of u and v, since undirected so u and v both are neighbours
        // of each other
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create a DS to store node visited or not
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclic(i, -1, adj, visited); // src node is always -1
            if (ans)
                return "Yes";
        }
    }
    return "No";
}
