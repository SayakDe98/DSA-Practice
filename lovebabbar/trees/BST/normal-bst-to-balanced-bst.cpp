/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int> *root, vector<int> &inorderVal)
{
    if (root == NULL)
        return;
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}

TreeNode<int> *solve(TreeNode<int> *root, int startIndex, int endIndex, vector<int> &inorderVal)
{
    if (startIndex > endIndex)
    {
        return NULL;
    }
    int mid = (startIndex + endIndex) / 2;
    TreeNode<int> *newRoot = new TreeNode<int>(inorderVal[mid]);
    newRoot->left = solve(root, startIndex, mid - 1, inorderVal);
    newRoot->right = solve(root, mid + 1, endIndex, inorderVal);
    return newRoot;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int startIndex = 0;
    int endIndex = inorderVal.size() - 1;

    return solve(root, startIndex, endIndex, inorderVal);
}
