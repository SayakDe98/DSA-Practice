template<typename T>
class Node{
    T data;
    Node<T> *next;

    public:
        Node(T data){
            this->data = data;
            next = NULL;
        }
}

//Creating a Node in Main
Node<int> *n = new Node<int>(10);//Node is of type int and it has value of 10
//data is 10 and next is NULL
// 0xABC is address of the node suppose because it is hecxdecimal
// Node contains both data and address whereas Node* contains only address
