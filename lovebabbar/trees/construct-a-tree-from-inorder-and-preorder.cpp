//{ Driver Code Starts
//

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

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    // int findPosition(int in[], int element, int n) {
    //     for(int i = 0; i < n; i++) {
    //         if(in[i] == element) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }

    Node *solve(int in[], int pre[], int &index, int inorderStartingIndex, int inorderEndingIndex, int n, map<int, int> &nodeToIndex)
    {
        // base case
        if (index >= n || inorderStartingIndex > inorderEndingIndex)
        {
            return NULL; // index>=n means whole array is covered, inorderStartingIndex > inorderEndingIndex means when end is smaller than start
        }
        int element = pre[index++]; // get starting element from preorder
        Node *root = new Node(element); // create a root node
        // int position = findPosition(in, element, n);
        int position = nodeToIndex[element];//find position of node
        // recursive calls
        root->left = solve(in, pre, index, inorderStartingIndex, position - 1, n, nodeToIndex);

        root->right = solve(in, pre, index, position + 1, inorderEndingIndex, n, nodeToIndex);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        // create nodes to index mapping
        createMapping(in, nodeToIndex, n);
        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends