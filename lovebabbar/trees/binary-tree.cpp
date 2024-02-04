#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
    node (int d) { // when we create a new node this happens
        this -> data = d; // we assign d as data
        this -> left = NULL; // we assign left as NULL as we have no child
        this -> right = NULL; // we assign right as NULL as we have no child
    }
};

node* buildTree (node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data); //we created a root node and give a value to root node

    if (data == -1) { // if we don't want to have left / right child then enter -1
        return NULL;
    }

    cout << "Enter data for inserting in left of " << root -> data << endl;
    root -> left = buildTree(root -> left); // recursion for building tree for left child of root node

    cout << "Enter data for inserting in right of " << root -> data << endl;
    root->right = buildTree(root->right); // recursion for building tree for right child of root node

    return root;//once we inputed the values of root, left & right subtree we return the root since building root is complete
}

void levelOrderTraversal (node* root) {
    queue<node*> q; // create a queue
    q.push(root); // push the root in queue
    q.push(NULL); // adding separator for root level(level 0)
    while(!q.empty()) {
        node* temp = q.front(); // take the front of queue and put it in temp
        q.pop(); // pop the front of queue

        if(temp == NULL) {
            //previous level is complete
            cout << endl;//going to next line for separator
            if(!q.empty()) { // queue still has child nodes
                q.push(NULL); // adding a separator for child nodes
            }
        } else {
            cout << temp -> data << " "; // print the current node
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

void inOrderTraversal (node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root -> left); // L
    cout << root -> data << " "; // N
    inOrderTraversal(root -> right); // R
}

void preOrderTraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root -> data << " "; // N
    preOrderTraversal(root -> left); // L
    preOrderTraversal(root -> right); // R
}

void postOrderTraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root -> left); // L
    postOrderTraversal(root -> right); // R
    cout << root -> data << " "; // N  
}

node* buildFromLevelOrder(node* &root) {
    queue<node*> q;//for level order use queue
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of: " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {//if not NULL insert otherwise ignore
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter data for right node of: " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        { // if not NULL insert otherwise ignore
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

int main () {
    node* root = NULL;

    // //creating a tree
    // root = buildTree(root);//input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // //do level order traversal
    // cout << "Printing the level order traversal output " << endl;
    // levelOrderTraversal(root);

    // // do in order traversal
    // cout << "Printing the in order traversal output " << endl;
    // inOrderTraversal(root);

    // // do pre order traversal
    // cout << "Printing the pre order traversal output " << endl;
    // preOrderTraversal(root);

    // // do post order traversal
    // cout << "Printing the post order traversal output " << endl;
    // postOrderTraversal(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    return 0;
}