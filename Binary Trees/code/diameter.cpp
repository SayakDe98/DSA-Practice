#include<iostream>
#include<queue>
using namespace std;

class node {
    public: 
        int data;
        node * left;
        node * right;

        node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node * buildTree() {
    int d;
    cin >> d;

    if(d == -1) {
        return NULL;
    }

    node * n = new node(d);
    n -> left = buildTree();
    n -> right = buildTree();

    return n;
}

void levelOrderPrint(node * root) {
    queue<node *> q;//we are not creating a copy of node which will waste memory so we are doing node *  instead of node
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node * temp = q.front();

        if(temp == NULL) {
            cout << endl;
            q.pop();
            //insert a new NULL for the next level
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            q.pop();
            cout << temp -> data << " ";

            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
    return;
}

//Helper function to get height of the tree
int height(node * root) {
    if(root == NULL)
        return 0;
    
    int h1 = height(root -> left);
    int h2 = height(root -> right);

    return 1 + max(h1, h2);
}

int diameter(node * root) {
    //base case
    if(root == NULL) 
        return 0;
    
    //recursive case
    int D1 = height(root -> left) + height(root -> right);
    int D2 = diameter(root -> left);
    int D3 = diameter(root -> right);

    return max(D1, max(D2, D3));
}

int main() {
    node * root = buildTree();
    // node * root = levelOrderBuild();
    levelOrderPrint(root);
    cout << "Diameter is " << diameter(root) << endl;
    return 0;
}
//TC:O(N^2)