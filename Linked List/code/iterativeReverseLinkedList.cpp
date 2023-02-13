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

void printLinkedList(node * head) {
    //base case
    if(head == NULL) {
        return;
    }

    //otherwise
    while(head != NULL) {
        head -> next != NULL && (cout << head -> data << "-->");
        head -> next == NULL && (cout << head -> data);
        head = head -> next;
    }    

    cout << endl;
}

void reverse(node * &head) {
     //if empty LL
    if(head == NULL) {
        return;
    }

    //create required nodes
    node * prev = NULL;
    node * current = head;
    node * temp;

    while(current != NULL) { //unless we reach the end of LL
        //store the next node
        temp = current -> next;
        //point the next of current to prev
        current -> next = prev;

        //redefine prev and current
        prev = current;
        current = temp;
    }

    head = prev;
    return;
}

int main() {
    node * head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    cout << "Normal Direction:" << endl;
    //normal direction
    printLinkedList(head);

    reverse(head);
    //reverse direction
    cout << "Reverse Direction" << endl;
    printLinkedList(head);
    return 0;
}