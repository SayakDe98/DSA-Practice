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
    n->next = head;
    head = n;
}

void printLinkedList(node * head) {
    while(head != NULL) {
        if(head -> next != NULL)
            cout << head -> data << "-->";
        else cout << head -> data;
        head = head -> next;
    }
    cout << endl;
}

void insertInMiddle(node * &head, int data, int pos) {
    if(pos == 0) {
        insertAtHead(head, data);
    }

    else {
        node * temp = head;
        for(int jump = 1; jump <= pos - 1; jump++) {
            temp = temp -> next;
        }

        node * n = new node(data);
        n -> next = temp -> next;
        temp -> next = n;
    }
}

int main() {
    node * head = NULL;

    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 7);

    printLinkedList(head);

    insertInMiddle(head, 100 ,3);    

    printLinkedList(head);

    insertInMiddle(head, 200 , 3);

    printLinkedList(head);
    return 0;
}






















