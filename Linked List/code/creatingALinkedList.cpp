#include<iostream>
using namespace std;

class node {//create a resuable class node
public://have an access specifier of public such that it can be used from anywhere
    int data;
    node * next;//define a node named next

    node(int data) {//we are creating the node object
        this->data = data; //this is a pointer which refers to the current node object. If you are accessing some property then use an arrow
        //we are also using this because name of parameter and variable is same.
        next = NULL;
    }

    // node * getNext() {
    //     //getter function
    // }

    // int getData() {
    //     //setter function
    // }
};

void insertAtHead(node * &head, int data) {//passing head obj as reference because if not done cahnges won't be reflected inside main function, we are passing address 
    if(head == NULL){//when head is NULL
        head = new node(data);//we point to a new node with some data
        return;
    }

    //otherwise
    node * n = new node(data);
    n->next = head;
    head = n;
}

void printLinkedList(node * head) {//can pass it by value or reference if we are not changing it, then it doesn't matter
    while(head != NULL) {
        head->next != NULL && (cout << head->data << "-->");
        head->next == NULL && (cout << head->data);
        head = head->next;
    }
    cout << endl;
}

int main() {
    node * head = NULL;//can be NULL by default

    insertAtHead(head, 4);    
    insertAtHead(head, 3);    
    insertAtHead(head, 2);    
    insertAtHead(head, 1);    
    insertAtHead(head, 0); 
    printLinkedList(head);   

    return 0;
}


















