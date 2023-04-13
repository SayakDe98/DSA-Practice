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

node * levelOrderBuild() {
    int d;
    cin >> d;
    node * root = new node(d);

    queue<node *> q;
    q.push(root);

    while(!q.empty()) {
        node * current = q.front();
        q.pop();

        int child1, child2;
        cin >> child1 >> child2;

        if(child1 != -1) {
            current -> left = new node(child1);
            q.push(current -> left);
        } if(child2 != -1) {
            current -> right = new node(child2);
            q.push(current -> right);
        }
    }

    return root;
}

int main() {
    // node * root = buildTree();
    node * root = levelOrderBuild();
    levelOrderPrint(root);
    return 0;
}