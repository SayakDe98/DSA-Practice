//This is also known as floyd cycle's algorithm
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

    node * n = new node(data);
    n -> next = head;
    head = n;
}


    bool cycleExists(node * head) {
    node * slowPointer = head;
    node * fastPointer = head;

    while(slowPointer != NULL and fastPointer != NULL and fastPointer ->next != NULL) {
        slowPointer = slowPointer -> next;
        fastPointer = fastPointer -> next -> next;

        if(slowPointer == fastPointer) {
            return true;
        }
    }

    return false;
}

int main() {
    node * head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);

    //adding loop
    node * temp = head;

    while(temp -> next != NULL)
        temp = temp -> next;
    
    temp -> next = head;
    //loop added successfully

    //check if cycle exists using && operator instead of if else cases
    cycleExists(head) && cout << "Cycle Exists" << endl;
    !cycleExists(head) && cout << "Cycle Doesn't Exist" << endl;
    return 0;
}