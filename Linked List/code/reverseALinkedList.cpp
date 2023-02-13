//hint: use recursion
#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node * next;

    node(int data) {
        this -> data = data;
        next = NULL;
    }
};

void insertAtHead(node * &head, int data) {
    if(head == NULL) {
        head = new node(data);
    }

    else if(head != NULL) {
        node * n = new node(data);
        n -> next = head;
        head = n;
    }
}

node * recursiveReverse(node * head) {
    //base case
    if(head == NULL or head -> next == NULL) {
        return head;
    }

    //otherwise
    node * smallHead = recursiveReverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return smallHead;
}

void printLinkedList(node * head) {
    if(head == NULL) {
        return;
    }

    while(head != NULL) {
        head -> next != NULL && (cout << head -> data << "-->");
        head -> next == NULL && (cout << head -> data);
        head = head -> next;
    }

    cout << endl;
}

int main() {
    node * head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    
    cout << "Original Linked List" << endl;

    printLinkedList(head);

    head = recursiveReverse(head);

    cout << "Reversed Linked List" << endl;

    printLinkedList(head);
    return 0;
}
