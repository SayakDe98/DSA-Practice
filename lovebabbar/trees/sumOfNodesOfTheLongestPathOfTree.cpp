//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
private:
    void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
    {
        // base case
        if (root == NULL)
        { // if we reach a leaf node
            if (len > maxLen)
            { // we check if curr length is greater than current maximum length we update both sum and length
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen)
            { // we check if current length is equal to maximum length we compare the max sum and current sum
                maxSum = max(sum, maxSum);
            }
            return;
        }

        sum += root->data; // we add data of current node to sum

        solve(root->left, sum, maxSum, len + 1, maxLen);  // we recursively solve for root -> left
        solve(root->right, sum, maxSum, len + 1, maxLen); // we recursively solve for root -> right
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        int len = 0;    // curr length
        int maxLen = 0; // maximum length

        int sum = 0;          // curr sum
        int maxSum = INT_MIN; // maximum sum

        solve(root, sum, maxSum, len, maxLen); // we recursively solve for current node
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends