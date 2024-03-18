/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    // Find key
    TreeNode *temp = root; // temp pointer to store root
    int predecessor = -1;  // initalize with -1
    int successor = -1;    // initalize with -1
    while (temp != NULL && temp->data != key)
    { // run a loop till we get a node with data == key
        if (temp->data > key)
        {                           // if current node has data greater than key
            successor = temp->data; // this can be a possible successor so store it

            temp = temp->left; // key must be in left part
        }
        else
        {                             // if current node has data lesser than key
            predecessor = temp->data; // this can be a possible predecessor so store it

            // go to right part since key is smaller than temp->data
            temp = temp->right;
        }
    }

    // predecessor and successor
    if (temp != NULL)
    {

        // Find predecessor
        TreeNode *leftTree = temp->left;
        while (leftTree != NULL)
        {                                 // run a loop to find the maximum value in the left subtree
            predecessor = leftTree->data; // this may be the predeccessor
            leftTree = leftTree->right;   // for finding maximum value
        }

        // Find successor
        TreeNode *rightTree = temp->right;
        while (rightTree != NULL)
        {                                // run a loop to find the minimum value in the right subtree
            successor = rightTree->data; // this can be a possible successor so store it
            rightTree = rightTree->left; // for finding minimum value
        }
    }

    pair<int, int> ans = make_pair(predecessor, successor); // create a pair to store the predecessor and successor
    return ans;
}