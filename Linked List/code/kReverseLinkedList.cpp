//Given a linked list, write a function to reverse every k nodes(where k is an input to the function).
//Input: 1->2->3->4->5->6->7->8->NULL, K = 3
//Output: 3->2->1->6->5->4->8->7->NULL

//For above example: we take 3 at a time.
//firstly reverse 1,2,3 we get 3,2,1
//secondly reverse 4,5,6 we get 6,5,4
//lastly reverse remaining 7,8 we get 8,7

#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node * next;

        node(int data) {
            this->data = data;
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

node * kReverse(node * head, int k) {
    //if empty LL
    if(head == NULL) {
        return NULL;
    }

    //create required nodes
    node * prev = NULL;
    node * current = head;
    node * temp;
    int count = 1;

    while(current != NULL and count <= k) { //unless we reach the end of LL
        //store the next node
        temp = current -> next;
        //point the next of current to prev
        current -> next = prev;

        //redefine prev and current
        prev = current;
        current = temp;
        k++;
    }

    if(temp != NULL) {
        head -> next = kReverse(temp, k);
    }

    return prev;
}

int main() {
    node * head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    
    printLinkedList(head);

    head = kReverse(head, 3);
    
    printLinkedList(head);
    return 0;
}