#include<iostream>
#include<queue>
using namespace std;

//create a class for Node definition
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        // creating a constructor
        Node(int data) {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* insertIntoBST(Node* &root, int data) {
    if(root == NULL) { // at starting there will be no tree so this handles that case
       root = new Node(data); 
       return root;
    }

    if(data < root->data) {
        // enter into left subtree since data is less than root's data
        insertIntoBST(root -> left, data);
    } else {
        // enter into right subtree since data is less than root's data
        insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1) {
        insertIntoBST(root, data);//insert into BST till we get -1
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q; // create a queue
    q.push(root);    // push the root in queue
    q.push(NULL);    // adding separator for root level(level 0)
    while (!q.empty())
    {
        Node *temp = q.front(); // take the front of queue and put it in temp
        q.pop();                // pop the front of queue

        if (temp == NULL)
        {
            // previous level is complete
            cout << endl; // going to next line for separator
            if (!q.empty())
            {                 // queue still has child nodes
                q.push(NULL); // adding a separator for child nodes
            }
        }
        else
        {
            cout << temp->data << " "; // print the current node
            if (temp->left)
            {
                q.push(temp->left); // push the left child into queue
            }

            if (temp->right)
            {
                q.push(temp->right); // push the right child into queue
            }
        }
    }
}

void inOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);  // L
    cout << root->data << " ";     // N
    inOrderTraversal(root->right); // R
}

void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";      // N
    preOrderTraversal(root->left);  // L
    preOrderTraversal(root->right); // R
}

void postOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);  // L
    postOrderTraversal(root->right); // R
    cout << root->data << " ";       // N
}

// Recursive traversal
// void minValueOfBST(Node* &root, int& mini) {
//     if(root == NULL) // If there is no node return
//         return;
//     if(root->left == NULL) { // if root's left subtree exist keep going to left and assign root's data to mini
//         mini = root->data; // assign the value of root data to mini
//         return; // return to prevent anymore useless recursive steps
//     }
//     minValueOfBST(root->left, mini); // call recursion on the left subtree because a left subtree exists where we will get mini
// }

// Iterative traversal
Node* minValueOfBST(Node* &root) {
    Node *temp = root; // copy root Node to temp
    while (temp->left != NULL) // keep running a loop till we don't get any left subtree anymore
    {
        temp = temp->left; // point temp's left subtree to temp now
    }
    return temp; // return temp node
}

// recursive traversal
//  void maxValueOfBST(Node* & root, int& maxi) {
//      if(root == NULL) // If there is no node return
//          return;
//      if(root->right == NULL) {// if root's right subtree exist keep going to right and assign root's data to maxi
//          maxi = root->data; // assign the value of root data to maxi
//          return; // return to prevent anymore useless recursive steps
//      }
//      maxValueOfBST(root->right, maxi); // call recursion on the right subtree because a right subtree exists where we will get maxi
//  }

Node* maxValueOfBST(Node* &root) {
    Node *temp = root; // copy root Node to temp
    while(temp->right != NULL)
    { // keep running a loop till we don't get any right subtree anymore
        temp = temp->right; // point temp's left subtree to temp now
    }
    return temp; // return temp node
}

Node* deleteNode(Node* &root, int x) {
    // base case
    if(root == NULL) {
        return root;
    }
    if(root->data == x) {
        // case 1: temp has no children, then simply remove the node and pass NULL to its parent
        if(root->left == NULL && root->right == NULL) {
            delete root; // // delete current node by freeing root's memory
            return NULL;
        }
        // case 2: 1 child: left child or right child
        // left child present only: store left child and then remove the current node and pass the left child to parent
        // right child present only: store right child and then remove the current node and pass the right child to parent
        if(root -> left != NULL && root->right == NULL) { // only left child present
            Node* temp = root->left; // store the left subtree
            delete root; // delete current node
            return temp; // pass the left child to parent
        }
        if (root->left == NULL && root->right != NULL)
        {                            // only right child present
            Node *temp = root->right; // store the right subtree
            delete root;             // delete current node
            return temp;             // pass the right child to parent
        }
        // case 3: temp has two children
        // get the max value of left subtree and put the value inplace of the current node
        // delete the max value of left subtree in the left subtree
        // get the min value of right subtree and put the value inplace of the current node
        // delete the min value of right subtree in the right subtree
        if(root->left != NULL && root->right != NULL) {
            // we can do either min value of right subtree or max value of left subtree
            int mini = minValueOfBST(root->right)->data; // gets minimum value from right subtree
            root->data = mini; // copy this data to root node's data
            root->right = deleteNode(root->right, mini);// delete this node from root's right subtree
            return root;
        }
    } else if (root->data > x)
    {
        root->left = deleteNode(root->left, x); // go to left subtree
    } else
    {
        root-> right = deleteNode(root->right, x); // go to right subtree
    }
    return root;
}

int main() {
    Node* root = NULL; // at starting root is NULL since there is no tree at beginning
    cout << "Enter data to create BST: " << endl;

    takeInput(root); // T.C.: O(logn)
    // cout << "Pre order traversal" << endl;
    // preOrderTraversal(root);
    // cout << endl;
    // cout << "Level Order Traversal" << endl;
    // levelOrderTraversal(root);
    // cout << endl;
    // cout << "Post Order Traversal" << endl;
    // postOrderTraversal(root);
    // int mini = -1;
    // int maxi = -1;
    // // minValueOfBST(root, mini);
    // Node* minValue = minValueOfBST(root);
    // // maxValueOfBST(root, maxi);
    // Node* maxValue = maxValueOfBST(root);
    // // cout << "Minimum value of BST: " << mini << ", maximum value of BST: " << maxi << "." <<endl;
    // cout << "Minimum value of BST: " << minValue -> data << ", maximum value of BST: " << maxValue -> data << "." << endl;
    cout << "Level Order Traversal before deletion" << endl;
    levelOrderTraversal(root);
    root = deleteNode(root, 30);
    cout << "Level Order Traversal after deletion" << endl;
    levelOrderTraversal(root);
    return 0;
}