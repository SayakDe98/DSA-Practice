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

void insertAtHead(node * &head , int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }

    node * n = new node(data);
    n -> next = head;
    head = n;
}

int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    node * fast = head;
    node * slow = head;
    int count = 0;
    
    while(count < k) {
        fast = fast -> next;
        count++;
    }
    
    while(fast != NULL) {
        slow = slow -> next;
        fast = fast -> next;
    }
    
    return slow -> data;
}

int main() {
    node * head = NULL;

    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << kthLastElement(head, 3) << endl;
    return 0;
}