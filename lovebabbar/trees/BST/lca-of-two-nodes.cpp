/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    // Recursive approach
    // base case
    // if(root == NULL) { // if no node exists return NULL
    //     return NULL;
    // }

    // if(root->data < P->data && root->data < Q->data) { // when nodes lie in right subtree
    //     return LCAinaBST(root->right, P, Q); // TC: O(n), SC: O(n)
    // }

    // if(root->data > P->data && root->data > Q->data) { // when nodes lie in left subtree
    //     return LCAinaBST(root->left, P, Q);// TC: O(n), SC: O(n)
    // }

    // return root; // we found root because root lies between P and Q

    // Iterative solution
    // base case

    if (root == NULL)
    {
        return NULL; // if no node exists return NULL
    }

    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
        {                       // when nodes lie in right subtree
            root = root->right; // TC: O(n), SC: O(1)
        }
        else if (root->data > P->data && root->data > Q->data)
        {                      // TC: O(n), SC: O(1)
            root = root->left; // when nodes lie in left subtree
        }
        else
        {
            return root;
        }
    }
} 