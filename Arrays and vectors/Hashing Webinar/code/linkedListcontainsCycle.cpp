#include<iostream>
#include<unordered_map>

using namespace std;

class node{
    public:
            int data;
            node* next;

            node(int data)
            {
                this->data = data;
                next = NULL;
            }
};

bool containsCycle(node *head)
{
    unordered_map<node* , bool> hashtable;

    node * temp = head;
    while(temp!=NULL)
    {
        //check if temp aready exists in the hashtable
        if(hashtable.count(temp)!=0)
        {
            return true;//if this value isn't present in hashtable then we return true
        }
        //insert in the hashtable
        hashtable[temp] = true;
        temp = temp->next;
    }
    return false;
}

void insertAtHead(node * &head, int value)
{
    if(head == NULL)
    {
        head = new node(value);
        return;
    }   
    node*n = new node(value);//initialize a new node with value as value
    n->next = head;//attach n's next pointer to head
    head = n;//make n node as head

}

int main()
{
    node * a = NULL;
    insertAtHead(a,1);
    insertAtHead(a,2);
    insertAtHead(a,3);
    insertAtHead(a,3);
    insertAtHead(a,3);

    //Creating the cycle:
    node*temp = a->next->next->next->next;
    temp->next = a->next->next;

    //Checking if cycle exists:
    if(containsCycle(a))
    {
        cout<<"Cycle found" << endl;
    }
    else{
        cout<<"Cycle not found" <<endl;
    }

    return 0;
}