//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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
    Node *root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution
{
public:
    int height(Node *&root)
    {
        if (root == NULL)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    pair<int, int> diameterFast(Node *root)
    {
        pair<int, int> p = make_pair(0, 0); // initializing a pair with {0, 0}
        if (root == NULL)
            return p;                                     // if root is NULL return {0,0}
        pair<int, int> left = diameterFast(root->left);   // find diameter of left of root
        pair<int, int> right = diameterFast(root->right); // find diameter of right of root

        int leftDiameter = left.first;                             // store left diameter for path going only through left subtree
        int rightDiameter = right.first;                           // store right diameter for path going only through right subtree
        int leftRootRightHeights = left.second + 1 + right.second; // store the heights of the left, right and root for path which is going through root

        pair<int, int> ans;
        ans.first = max(max(leftDiameter, rightDiameter), leftRootRightHeights); // store the diameter
        ans.second = max(left.second, right.second) + 1;                         // store the height
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *&root)
    {
        // Your code here
        // if(root == NULL)
        //     return 0;
        // int leftDiameter = diameter(root -> left);
        // int rightDiameter = diameter(root -> right);
        // int leftRootRightHeights = height(root -> left) + 1 + height(root -> right);
        // return max(leftDiameter, max(rightDiameter, leftRootRightHeights));
        return diameterFast(root).first; // return the diameter of root
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends