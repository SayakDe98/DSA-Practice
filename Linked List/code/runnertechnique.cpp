#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
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

int getMid(node *head){
    //Complete this function to return data middle node
    if(head == NULL) {
        return -1;
    }
    
    if(head -> next == NULL) {
        return head -> data;
    }
    node * fast = head -> next;
    node * slow = head;
    
    while(fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    return slow -> data;   
}

int main() {
    node * head = NULL;

    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << getMid(head) << endl;
}