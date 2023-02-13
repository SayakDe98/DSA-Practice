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
    if(a == NULL) {
        return b;
    }

    if(b == NULL) {
        return a;
    }

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

node * midPoint(node * head) {
    node * slow = head;
    node * fast = head -> next;

    while(fast != NULL and fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

node * mergeSort(node * head) {
    //base case
    //smallest linked list can have 0 nodes or 1 node
    if(head == NULL or head -> next == NULL) {
        return head;
    }

    //recursive case
    node * mid = midPoint(head);

    //break at mid
    node * a = head;
    node * b = mid -> next;
    mid -> next = NULL;

    //Recursive Sorting
    a = mergeSort(a);
    b = mergeSort(b);

    //merge the two sorted Linked List a and b
    return merge(a, b);
}

void printLinkedList(node * head) {
    if(head == NULL) {
        return;
    }    

    while(head != NULL) {
        if(head -> next == NULL) {
            cout << head -> data;
        }
        if(head -> next != NULL) {
            cout << head -> data << "-->";
        }

        head = head -> next;
    }
    cout << endl;
}

int main() {
    node * a = NULL;

    insertAtHead(a, 10);
    insertAtHead(a, 7);
    insertAtHead(a, 5);
    insertAtHead(a, 1);
    insertAtHead(a, 17);
    insertAtHead(a, 2);
    insertAtHead(a, 14);

    printLinkedList(a);

    a = mergeSort(a);

    printLinkedList(a);
    
    return 0;
}