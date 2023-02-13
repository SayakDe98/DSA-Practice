//Given two sorted linked lists merge them into a new linked list.

//Input:
//1->5->7->10->NULL
// 2->3->6->NULL

//Output:
//1->2->3->5->6->7->10->NULL

//We don't want to make a new Linked List we want to change the pointers
//First we will compare the first element of both the linked lists
//Let's take a new node which will be used to compare the first elements
//both the linked lists. 
//Now we need to make a recursive call for merging the first and second linked list
//If one of the linked list become NULL then simply return the linked list which is not null

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
        return;
    }

    node * n = new node(data);
    n -> next = head;
    head = n;
}

node * merge(node * a, node * b) {
    //base case
    if(a == NULL) {
        return b;
    }

    if(b == NULL) {
        return a;
    }

    //recursive case
    node * c;

    if(a -> data < b -> data) {
        c = a;
        c -> next = merge(a -> next, b);
    } else {
        c = b;
        c -> next = merge(a, b -> next);
    }

    return c;
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
}

int main() {
    node * a = NULL;

    insertAtHead(a, 10);
    insertAtHead(a, 7);
    insertAtHead(a, 5);
    insertAtHead(a, 1);

    node * b = NULL;
    
    insertAtHead(b, 6);
    insertAtHead(b, 3);
    insertAtHead(b, 2);

    node * head = merge(a, b);

    printLinkedList(head);

    return 0;
}