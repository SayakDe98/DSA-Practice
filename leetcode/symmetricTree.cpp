// 101. Symmetric Tree
//     Easy

//     14351

//     333

//     Add to List

//         Share
//             Given the root of a binary tree,
//     check whether it is a mirror of itself(i.e., symmetric around its center).

//     Example 1 :

//     Input : root = [ 1, 2, 2, 3, 4, 4, 3 ] Output : true Example 2 :

//     Input : root = [ 1, 2, 2, null, 3, null, 3 ] Output : false

//                                                           Constraints :

//     The number of nodes in the tree is in the range[1, 1000]
//         .- 100 <= Node.val
//                    <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool twoNodesSame(TreeNode *left, TreeNode *right)
    {
        // If both nodes are null, they are considered the same
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        // If one of the nodes is null or their values are not the same, they are not the same
        if (left == nullptr || right == nullptr || left->val != right->val)
        {
            return false;
        }

        // Check if the left subtree's left is the same as the right subtree's right
        // and if the left subtree's right is the same as the right subtree's left
        return twoNodesSame(left->left, right->right) && twoNodesSame(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        // Helper function to compare two subtrees

        // Check if the tree is symmetric starting from the root
        if (root == nullptr)
        {
            return true;
        }

        return twoNodesSame(root->left, root->right);
    }
};
